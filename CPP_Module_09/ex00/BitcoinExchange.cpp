#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: mDataFilePath(DATA_CSV)
	, mInputFilePath()
	, mDataFile(DATA_CSV)
	, mInputFile()
	, mErrorMSG()
	, mBitcoinDatabase()
{
}

BitcoinExchange::BitcoinExchange(const char* filePath)
	: mDataFilePath(DATA_CSV)
	, mInputFilePath(filePath)
	, mDataFile(DATA_CSV)
	, mInputFile(filePath)
	, mErrorMSG()
	, mBitcoinDatabase()
{
	try
	{
		LoadBitcoinDatabase();
		SaveData();
		LoadInputDatabase();
		Calculate();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: mDataFilePath(other.mDataFilePath)
	, mInputFilePath(other.mInputFilePath)
	, mErrorMSG(other.mErrorMSG)
	, mBitcoinDatabase(other.mBitcoinDatabase)
{
	try 
	{
		OpenFiles();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		mDataFilePath = other.mDataFilePath;
		mInputFilePath = other.mInputFilePath;
		mErrorMSG = other.mErrorMSG;
		mBitcoinDatabase = other.mBitcoinDatabase;
		try 
		{
			OpenFiles();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	mDataFile.close();
	mInputFile.close();
}

void BitcoinExchange::OpenFiles()
{
	mDataFile.close();
	mInputFile.close();
	
	if (mDataFilePath.empty() == false)
	{
		mDataFile.open(mDataFilePath.c_str());
		if (mDataFile.is_open() == false)
		{
			throw std::runtime_error("Error: File open failed.");
		}
	}
	if (mInputFilePath.empty() == false)
	{
		mInputFile.open(mInputFilePath.c_str());
		if (mInputFile.is_open() == false)
		{
			throw std::runtime_error("Error: File open failed.");
		}
	}
}

void BitcoinExchange::LoadBitcoinDatabase()
{
	// check extention
	if (CheckFileExtension(DATA_CSV, ".csv") == false)
	{
		throw std::runtime_error("Error: Invalid file extention.");
	}
	// open & permission denied error
	if (mDataFile.is_open() == false)
	{
		throw std::runtime_error("Error: File open failed.");
	}
}

void BitcoinExchange::SaveData()
{
	/* date , exchange_rate */
	std::string line;
	std::string date;
	std::string exchangeRate;
	double convertedExchangeRate;

	if (CheckDataFirstLine() == false)
	{
		throw std::runtime_error(mErrorMSG);
	}
	while (std::getline(mDataFile, line))
	{
		if (CheckFormat(line, date, DATA_FILE_SEPARATOR, exchangeRate) == false)
		{
			throw std::runtime_error(mErrorMSG);
		}
		if (CheckDate(date) == false)
		{
			throw std::runtime_error(mErrorMSG);
		}
		if (CheckExchangeRate(exchangeRate, convertedExchangeRate) == false)
		{
			throw std::runtime_error(mErrorMSG);
		}
		mBitcoinDatabase[date] = convertedExchangeRate;
	}
}

bool BitcoinExchange::CheckExchangeRate(const std::string& exchangeRate, double& outConvertedExchangeRate)
{
	int dotCount = std::count(exchangeRate.begin(), exchangeRate.end(), '.');

	std::string::const_iterator it = std::find_if(exchangeRate.begin(), exchangeRate.end(), IsNotDigitOrDot);

	if (1 < dotCount || it != exchangeRate.end())
	{
		mErrorMSG = "Error: Invalid exchange rate format.";
		return (false);
	}

    std::istringstream iss(exchangeRate);
    iss >> outConvertedExchangeRate;

    if (iss.fail() == true) 
    {
        mErrorMSG = "Error: Conversion resulted in overflow or underflow.";
        return (false);
    }

	return (true);
}


void BitcoinExchange::LoadInputDatabase()
{
	// check extention
	if (CheckFileExtension(mInputFilePath, ".txt") == false)
	{
		throw std::runtime_error("Error: Invalid file extention.");
	}
	// open & permission denied error
	if (mInputFile.is_open() == false)
	{
        throw std::runtime_error("Error: File open failed.");
	}
}

bool BitcoinExchange::CheckFileExtension(const std::string& path, const std::string& validExtension)
{
    if (path.length() <= validExtension.length())
	{
        return false;
    }

    std::string actualExtension = path.substr(path.length() - validExtension.length());

	if (actualExtension != validExtension)
	{
		return (false);
	}

	return (true);
}

void BitcoinExchange::Calculate()
{
	/* date | value */
	std::string line;
	std::string date;
	std::string value;
    float bitcoinPrice = 0.0f;
    double exchangeRate = 0.0;

	if (CheckInputFirstLine() == false)
	{
		std::cerr << mErrorMSG << std::endl;
	}
	while (std::getline(mInputFile, line))
	{
		if (CheckFormat(line, date, INPUT_FILE_SEPARATOR, value) == false)
		{
			std::cerr << mErrorMSG << std::endl;
			continue ; 
		}
		if (CheckDate(date) == false)
		{
			std::cerr << mErrorMSG << std::endl;
			continue ;
		}
		if (CheckBitcoinPrice(value, bitcoinPrice) == false)
		{
			std::cerr << mErrorMSG << std::endl;
			continue ;
		}
		if (FindClosetDateExchangeRate(date, exchangeRate) == false)
		{
			std::cerr << mErrorMSG << std::endl;
			continue ;
		}
		PrintBitcoinPrice(date, bitcoinPrice, exchangeRate);
	}
}

bool BitcoinExchange::CheckDataFirstLine()
{
	std::string line;

	std::getline(mDataFile, line);
	if (line != "date,exchange_rate")
	{
        mErrorMSG = "Error: Invalid format => " + line;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::CheckInputFirstLine()
{
	std::string line;

	std::getline(mInputFile, line);
	if (line != "date | value")
	{
        mErrorMSG = "Error: Invalid format => " + line;
		return (false);
	} 
	return (true);
}

bool BitcoinExchange::CheckFormat(std::string& line, std::string& outDate, char separator, std::string& outValue)
{
    size_t separatorPos = line.find(separator);

    if (separatorPos == std::string::npos || separatorPos != line.rfind(separator))
    {
        mErrorMSG = "Error: Invalid format => " + line;
        return (false);
    }

	// date | exchangeRate 	 date,exchange_rate
    outDate = line.substr(0, separatorPos);
    outValue = line.substr(separatorPos + 1);

	// erase ' '
    outDate.erase(0, outDate.find_first_not_of(" \t"));
    outDate.erase(outDate.find_last_not_of(" \t") + 1);

    outValue.erase(0, outValue.find_first_not_of(" \t"));
    outValue.erase(outValue.find_last_not_of(" \t") + 1);

	// ' ' == true : error
    if (outDate.find(' ') != std::string::npos || outValue.find(' ') != std::string::npos)
    {
        mErrorMSG = "Error: Invalid format => " + line;
        return (false);
    }

	if (outDate.empty() || outValue.empty())
	{
        mErrorMSG = "Error: Invalid format => " + line;
        return (false);
	}

    return (true);
}

bool BitcoinExchange:: CheckDate(const std::string& date)
{
	if (date.length() != 10)
	{
		mErrorMSG = "Error: Invalid date length.";
		return (false);
	}

	if (date[4] != '-' || date[7] != '-')
	{
		mErrorMSG = "Error: Invalid date format. Expected '-' separators.";
		return (false);
	}

	std::string stringYear = date.substr(0, 4);
	std::string stringMonth = date.substr(5, 2);
	std::string stringDay = date.substr(8, 2);


	for (size_t index = 0; index < stringYear.size(); index++)
	{
		if (isdigit(stringYear[index]) == false)
		{
			mErrorMSG = "Error: Invalid year format.";
			return (false);
		}
	}

	for (size_t index = 0; index < stringMonth.size(); index++)
	{
		if (isdigit(stringMonth[index]) == false)
		{
			mErrorMSG = "Error: Invalid month format.";
			return (false);
		}
	}

	for (size_t index = 0; index < stringDay.size(); index++)
	{
		if (isdigit(stringDay[index]) == false)
		{
			mErrorMSG = "Error: Invalid day format.";
			return (false);
		}
	}

	int year = std::atoi(stringYear.c_str());
	int month = std::atoi(stringMonth.c_str());
	int day = std::atoi(stringDay.c_str());

	if (year < 0 || 9999 < year)
	{
		mErrorMSG = "Error: Year out of range.";
		return (false);
	}

	if (month < 1 || 12 < month)
	{
		mErrorMSG = "Error: Month out of range.";
		return (false);
	}

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			daysInMonth[month - 1] = 29;
		}
	}

	if (day < 1 || daysInMonth[month - 1] < day)
	{
		mErrorMSG = "Error: Day out of range for given month.";
		return (false);
	}

	return (true);
}

bool IsNotDigitOrDot(const char c)
{
	if (isdigit(c) == true)
	{
		return (false);
	}

	if (c == '.')
	{
		return (false);
	}

	return (true);
}


bool IsNotValidChar(const char c)
{
    if (isdigit(c) == true)
	{
        return (false);
	}
    if (c == '.' || c == '-')
	{
        return (false);
	}
    return (true);
}

bool BitcoinExchange::CheckBitcoinPrice(const std::string& value, float& outBitcoinPrice)
{
	int minusCount = std::count(value.begin(), value.end(), '-');
	if (1 < minusCount || (minusCount == 1 && value[0] != '-'))
	{
		mErrorMSG = "Error: Invalid format with '-' character.";
		return (false);
	}

	int dotCount = std::count(value.begin(), value.end(), '.');
	if (1 < dotCount)
	{
		mErrorMSG = "Error: Multiple '.' characters detected.";
		return (false);
	}
	
	std::string::const_iterator it = std::find_if(value.begin(), value.end(), IsNotValidChar);
	if (it != value.end())
	{
		mErrorMSG = "Error: Invalid character detected.";
		return (false);
	}

	std::istringstream iss(value);
	iss >> outBitcoinPrice;

	if (iss.fail())
	{
		mErrorMSG = "Error: Conversion resulted in overflow or underflow.";
		return (false);
	}

	if (outBitcoinPrice < 0)
	{
        mErrorMSG = "Error: Not a positive number.";
        return (false);
	}
	if (1000 < outBitcoinPrice)
	{
        mErrorMSG = "Error: Too large a number.";
        return (false);
	}

	return (true);
}

bool BitcoinExchange::FindClosetDateExchangeRate(const std::string& date, double& outExchangeRate)
{
    std::map<std::string, double>::iterator it = mBitcoinDatabase.lower_bound(date);
    

    if (it == mBitcoinDatabase.end() || it->first != date)
	{
        if (it == mBitcoinDatabase.begin())
		{
            mErrorMSG = "Error: Could not find a closest date.";
            return (false);
        }
        --it;
    }
    
    outExchangeRate = it->second;
    return (true);
}

void BitcoinExchange::PrintBitcoinPrice(const std::string& date, const float bitcoinPrice, const double exchangeRate)
{
	// YYYY-MM-DD => bitcoinPrice = bitcoinPrice * exchangeValue
	std::cout << date;
	std::cout << " => ";
	std::cout << bitcoinPrice;
	std::cout << " = ";
	std::cout << bitcoinPrice * exchangeRate;
	std::cout << std::endl;
}
