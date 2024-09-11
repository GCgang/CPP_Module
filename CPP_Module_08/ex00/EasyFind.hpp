#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
    public:
        const char* what() const throw ()
        {
            return ("Target value not found in the container.");
        }
};

template <typename T>
typename T::iterator easyFind(T& container, int target);

template <typename T>
typename T::const_iterator easyFind(const T& container, int target);

template <typename Container>
void printContainer(const Container& container, const std::string& containerName);

#include "EasyFind.tpp"

#endif