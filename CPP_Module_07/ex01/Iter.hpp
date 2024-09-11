#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t arraySize, void (*function)(T&))
{
    for (size_t index = 0; index < arraySize; index++)
    {
        function(array[index]);
    }
}

template <typename T>
void print(T& printValue)
{
    std::cout << printValue << " ";
}

template <typename T>
void initializeToZero(T& value)
{
    value = 0;
}

template <>
void initializeToZero(std::string& value)
{
    value = "";
}

template <typename T>
void doubleValue(T& value)
{
    value *= 2;
}

template <>
void doubleValue(std::string& value)
{
    value += value;
}

#endif