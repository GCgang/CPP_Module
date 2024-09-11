#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits> 
#include <cstddef>

class Span
{
    public:
        Span();
        Span(unsigned int size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void AddNumber(int addNumber);

        template <typename IT>
        void AddRange(IT begin, IT end);

        std::size_t ShortestSpan();
        std::size_t LongestSpan();

        class OverflowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class RangeOverflowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class InsufficientNumbersException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        unsigned int mSize;
        std::vector<int> mVector;
};

#include "Span.tpp"

#endif