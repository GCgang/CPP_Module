#include "ScalarConverter.hpp"

bool ScalarConverter::isSpecialFloat(const std::string& inputString)
{
    return (inputString == "-inff" || inputString == "+inff" || inputString == "inff" || inputString == "nanf");
}

bool ScalarConverter::isSpecialDouble(const std::string& inputString)
{
    return (inputString == "-inf" || inputString == "+inf" || inputString == "inf" || inputString == "nan");
}

bool ScalarConverter::isPureInteger(const std::string& inputString) {
    for (size_t i = 0; i < inputString.length(); ++i) {
        if (!isdigit(inputString[i]) && inputString[i] != '-' && inputString[i] != '+') {
            return false;
        }
    }
    return true;
}

int ScalarConverter::tryParseChar(const std::string& inputString, char& outResult)
{
    if (inputString.length() == 1 && !std::isdigit(inputString[0]))
    {
        outResult = inputString[0];
        return 0;
    }
    return -1;
}

int ScalarConverter::tryParseInt(const std::string& inputString, int& outResult)
{
	if (inputString.empty() == true)
	{
		return (-1);
	} 
    errno = 0;
    char *end;
    long int longResult = strtol(inputString.c_str(), &end, 10);
    if (errno == ERANGE || longResult > INT_MAX || longResult < INT_MIN)
    {
        return -1;
    }
    if (*end == '\0')
    {
        outResult = static_cast<int>(longResult);
        return 0;
    }
    return -1;
}

float ScalarConverter::tryParseFloat(const std::string& inputString, float& outResult)
{
	if(isPureInteger(inputString))
	{
		return -1;
	}
    errno = 0;
    char *end;
    outResult = strtof(inputString.c_str(), &end);
    if (errno == ERANGE)
    {
        return -1;
    }
    if (*end == 'f' && *(end + 1) == '\0')
    {
        return 0;
    }
    return -1;
}

double ScalarConverter::tryParseDouble(const std::string& inputString, double& outResult)
{
	if(isPureInteger(inputString)) return -1;

    if(inputString.find("f") != std::string::npos) {
        return -1;
    }

    errno = 0;
    char *end;
    outResult = strtod(inputString.c_str(), &end);
    if (errno == ERANGE)
    {
        return -1;
    }
    if (*end == '.' || *end == '\0')
    {
        return 0;
    }
    return -1;
}

float ScalarConverter::getSpecialFloatValue(const std::string& inputString)
{
    if (inputString == "-inff")
	{
        return (-std::numeric_limits<float>::infinity());
    }
	else if (inputString == "+inff" || inputString == "inff")
	{
        return (std::numeric_limits<float>::infinity());
    }
	else
	{
        return (std::numeric_limits<float>::quiet_NaN());
    }
}

double ScalarConverter::getSpecialDoubleValue(const std::string& inputString)
{
    if (inputString == "-inf")
	{
        return -std::numeric_limits<double>::infinity();
    }
	else if (inputString == "+inf" || inputString == "inf")
	{
        return std::numeric_limits<double>::infinity();
    }
	else
	{
        return std::numeric_limits<double>::quiet_NaN();
    }
}

void ScalarConverter::printNoneType()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::Convert(const std::string& inputString)
{
	// char
    char charValue;
    if (tryParseChar(inputString, charValue) == 0)
    {
        outputCastedValues(charValue);
        return;
    }

	// int
    int intValue;
    if (tryParseInt(inputString, intValue) == 0)
	{
        outputCastedValues(intValue);
        return;
    }

		// special float
    if (isSpecialFloat(inputString))
	{
        float floatValue = getSpecialFloatValue(inputString);
        outputCastedValues(floatValue);
        return;
    }

	// float
    float floatValue;
    if (tryParseFloat(inputString, floatValue) == 0)
	{
        outputCastedValues(floatValue);
        return;
    }

	// special double
    if (isSpecialDouble(inputString))
	{
        double specialValue = getSpecialDoubleValue(inputString);
        outputCastedValues(specialValue);
		return;
    }

	// double
    double doubleValue;
    if (tryParseDouble(inputString, doubleValue) == 0)
	{
        outputCastedValues(doubleValue);
        return;
    }	

	return (printNoneType());
}

template <typename T>
void ScalarConverter::outputCastedValues(const T& value)
{
	// print char
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
	{
    	char cValue = static_cast<char>(value);
        if (isprint(cValue) == true)
		{
            std::cout << "char: '" << cValue << "'" << std::endl;
        }
		else
		{
            std::cout << "char: Non displayable" << std::endl;
        }
    }
	else
	{
        std::cout << "char: impossible" << std::endl;
    } 

	// print int
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
	{
    	int iValue = static_cast<int>(value);
        std::cout << "int: " << iValue << std::endl;
    }
	else
	{
        std::cout << "int: impossible" << std::endl;
    }

	// print float
	float fValue = static_cast<float>(value);
	if (fValue != fValue)
	{ 
		std::cout << "float: nanf" << std::endl;
	}
	else if (fValue == std::numeric_limits<float>::infinity() || fValue == -std::numeric_limits<float>::infinity())
	{
		std::cout << "float: ";
		std::cout << (fValue < 0 ? "-inff" : "+inff") << std::endl;
	}
	else
	{
		std::ostringstream f_ss;
		f_ss << fValue;
		std::string f_s = f_ss.str();
		char last_char_f = *(f_s.end() - 1);
		if (f_s.find('.') == std::string::npos || last_char_f == '.')
		{
			f_s += ".0";
		}
		std::cout << "float: "  << f_s << "f" << std::endl;
	}


	// print double
	double dValue = static_cast<double>(value);
	if (dValue != dValue)
	{
		std::cout << "double: nan" << std::endl;
	}
	else if (dValue == std::numeric_limits<double>::infinity() || dValue == -std::numeric_limits<double>::infinity())
	{
		std::cout << "double: ";
		std:: cout << (dValue < 0 ? "-inf" : "+inf") << std::endl;
	}
	else
	{
		std::ostringstream d_ss;
		d_ss << dValue;
		std::string d_s = d_ss.str();
		char last_char_d = *(d_s.end() - 1);
		if (d_s.find('.') == std::string::npos || last_char_d == '.')
		{
			d_s += ".0";
		}
		std::cout << "double: " << d_s << std::endl;
	}
}

