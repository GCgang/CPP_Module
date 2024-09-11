#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cerrno>
#include <climits>
#include <cstdlib>

class ScalarConverter
{
    public:
        static void Convert(const std::string& inputString);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

		static bool isSpecialFloat(const std::string& inputString);
		static bool isSpecialDouble(const std::string& inputString);
		static bool isPureInteger(const std::string& inputString);
		static int tryParseChar(const std::string& inputString, char& outResult);
		static int tryParseInt(const std::string& inputString, int& outResult);
		static float tryParseFloat(const std::string& inputString, float& outResult);
		static double tryParseDouble(const std::string& inputString, double& outResult);
		static float getSpecialFloatValue(const std::string& inputString);
		static double getSpecialDoubleValue(const std::string& inputString);
		static void printNoneType(void);
        
		template <typename T>
        static void outputCastedValues(const T &value);
};

#endif