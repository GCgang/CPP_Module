#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <map>

#define DATA_CSV "data.csv"
#define DATA_FILE_SEPARATOR ','
#define INPUT_FILE_SEPARATOR '|'

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const char* filePath);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void OpenFiles();
		bool CheckFileExtension(const std::string& path, const std::string& validExtension);

		void LoadBitcoinDatabase();
		void SaveData();
		bool CheckExchangeRate(const std::string& exchangeRate, double& outConvertedExchangeRate);
		
		void LoadInputDatabase();
		void Calculate();
		
		bool CheckDataFirstLine();
		bool CheckInputFirstLine();
		bool CheckFormat(std::string& line, std::string& outDate, char separator, std::string& outValue);
		bool CheckDate(const std::string& date);
		bool CheckBitcoinPrice(const std::string& value, float& outBitcoinPrice);
		bool FindClosetDateExchangeRate(const std::string& date, double& outExchangeRate);
		void PrintBitcoinPrice(const std::string& date, const float bitcoinPrice, const double exchangeRate);
	private:
		std::string mDataFilePath;
		std::string mInputFilePath;
		std::ifstream mDataFile;
		std::ifstream mInputFile;
		std::string mErrorMSG;
		std::map<std::string, double> mBitcoinDatabase;
};

bool IsNotDigitOrDot(const char c);
bool IsNotValidChar(const char c);

#endif


