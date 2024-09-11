#include "Span.hpp"

Span::Span()
    : mSize(0)
    , mVector()
{
}

Span::Span(unsigned int size)
    : mSize(size)
    , mVector()
{
    mVector.reserve(mSize);
}

Span::Span(const Span& other)
    : mSize(other.mSize)
    , mVector(other.mVector)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        mSize = other.mSize;
        mVector = other.mVector;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::AddNumber(int addNumber)
{
    if (mVector.size() >= mSize)
    {
        throw Span::OverflowException();
    }
    mVector.push_back(addNumber);
}

std::size_t Span::ShortestSpan()
{
    if (mVector.size() < 2)
    {
        throw Span::InsufficientNumbersException();
    }

    std::sort(mVector.begin(), mVector.end());

    std::size_t shortest = std::numeric_limits<std::size_t>::max();

    for (std::size_t index = 1; index < mVector.size(); index++)
    {
        shortest = std::min(shortest, static_cast<std::size_t>(mVector[index] - mVector[index - 1]));
    }
    
    return (shortest);
}

std::size_t Span::LongestSpan()
{
    if (mVector.size() < 2)
    {
        throw Span::InsufficientNumbersException();    
    }

    int minElement = *std::min_element(mVector.begin(), mVector.end());
    int maxElement = *std::max_element(mVector.begin(), mVector.end());

    std::size_t longestSpan = static_cast<std::size_t>(maxElement - minElement);

    return (longestSpan);
}

const char* Span::OverflowException::what() const throw()
{
    return ("Span is full, cannot add more numbers.");
}

const char* Span::RangeOverflowException::what() const throw()
{
    return ("Adding this range would exceed the Span's limit.");
}

const char* Span::InsufficientNumbersException::what() const throw()
{
    return ("Not enough numbers to calculate span.");
}