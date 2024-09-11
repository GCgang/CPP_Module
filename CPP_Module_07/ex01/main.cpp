#include <iostream>
#include "Iter.hpp"

int main()
{
	char charArr[] = {'1', '2', '3', '4', '5'};
    int intArr[] = {1, 2, 3, 4, 5};
    float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string strArr[] = {"one", "two", "three", "four", "five"};

	size_t charSize = sizeof(charArr) / sizeof(char);
    size_t intSize = sizeof(intArr) / sizeof(int);
    size_t floatSize = sizeof(floatArr) / sizeof(float);
    size_t strSize = sizeof(strArr) / sizeof(std::string);

    // Using print function
	std::cout << "Printing char array: ";
	iter(intArr, intSize, print);
	std::cout << std::endl;

    std::cout << "Printing integer array: ";
    iter(intArr, intSize, print);
    std::cout << std::endl;

    std::cout << "Printing string array: ";
    iter(strArr, strSize, print);
    std::cout << std::endl;

    std::cout << "Printing float array: "; 
    iter(floatArr, floatSize, print);
    std::cout << std::endl;
    std::cout << std::endl;

    // Using doubleValue function
    std::cout << "Doubling char array elements: ";
    iter(charArr, charSize, doubleValue);
    iter(charArr, charSize, print);
    std::cout << std::endl;

    std::cout << "Doubling int array elements: ";
    iter(intArr, intSize, doubleValue);
    iter(intArr, intSize, print);
    std::cout << std::endl;

    std::cout << "Doubling float array elements: ";
    iter(floatArr, floatSize, doubleValue);
    iter(floatArr, floatSize, print);
    std::cout << std::endl;

    std::cout << "Doubling string array elements: ";
    iter(strArr, strSize, doubleValue);
    iter(strArr, strSize, print);
    std::cout << std::endl;
    std::cout << std::endl;

    // Using initializeToZero function
    std::cout << "Initializing char array to zero: ";
    iter(charArr, charSize, initializeToZero);
    iter(charArr, charSize, print);
    std::cout << std::endl;
	
    std::cout << "Initializing integer array to zero: ";
    iter(intArr, intSize, initializeToZero);
    iter(intArr, intSize, print);
    std::cout << std::endl;	

    std::cout << "Initializing float array to zero: ";
    iter(floatArr, floatSize, initializeToZero);
    iter(floatArr, floatSize, print);
    std::cout << std::endl;
		
    std::cout << "Initializing string array to zero: ";
    iter(strArr, strSize, initializeToZero);
    iter(strArr, strSize, print);
    std::cout << std::endl;

    return 0;
}