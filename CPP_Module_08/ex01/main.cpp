#include <iostream>
#include <deque>
#include "Span.hpp"

int main() {
    // Basic test
    Span sp1(5);
    sp1.AddNumber(6);
    sp1.AddNumber(3);
    sp1.AddNumber(17);
    sp1.AddNumber(9);
    sp1.AddNumber(11);
    std::cout << "Shortest span (sp1): " << sp1.ShortestSpan() << std::endl;
    std::cout << "Longest span (sp1): " << sp1.LongestSpan() << std::endl;
    std::cout << std::endl;
    // Testing OverflowException
    try {
        sp1.AddNumber(20);
    } catch (const Span::OverflowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Testing RangeOverflowException
    Span sp2(10);
    std::vector<int> numbers(11, 0);  // 11 zeros
    try {
        sp2.AddRange(numbers.begin(), numbers.end());
    } catch (const Span::RangeOverflowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Testing InsufficientNumbersException with ShortestSpan
    Span sp3(5);
    sp3.AddNumber(1);
    try {
        std::cout << "Shortest span (sp3): " << sp3.ShortestSpan() << std::endl;
    } catch (const Span::InsufficientNumbersException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Testing InsufficientNumbersException with LongestSpan
    try {
        std::cout << "Longest span (sp3): " << sp3.LongestSpan() << std::endl;
    } catch (const Span::InsufficientNumbersException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Copy constructor and assignment operator tests
    Span sp4 = sp1;  // Using copy constructor
    std::cout << "Shortest span (sp4): " << sp4.ShortestSpan() << std::endl;
    std::cout << std::endl;

    Span sp5(1);
    sp5 = sp1;  // Using copy assignment operator
    std::cout << "Longest span (sp5): " << sp5.LongestSpan() << std::endl;
    std::cout << std::endl;

    // Testing with a large number of elements
	Span sp6(10000);
	std::vector<int> largeNumbers;
	largeNumbers.reserve(10000);
	for(int i = 0; i < 10000; ++i) {
		largeNumbers.push_back(i);
	}

    sp6.AddRange(largeNumbers.begin(), largeNumbers.end());
    std::cout << "Shortest span (sp6): " << sp6.ShortestSpan() << std::endl;
    std::cout << "Longest span (sp6): " << sp6.LongestSpan() << std::endl;
    std::cout << std::endl;

	Span sp7(20000);
	std::deque<int> dequeLargeNumbers;
	for(int i = 0; i < 20001; ++i) {
		dequeLargeNumbers.push_back(i);
	}
	try {
	    sp7.AddRange(dequeLargeNumbers.begin(), dequeLargeNumbers.end());	
		std::cout << "Shortest span (sp7): " << sp7.ShortestSpan() << std::endl;
		std::cout << "Longest span (sp7): " << sp7.LongestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
	}
    return 0;
}
