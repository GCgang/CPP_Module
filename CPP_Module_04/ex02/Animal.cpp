#include "Animal.hpp"

Animal::Animal()
    : mType("Animal")
{
    std::cout << "Animal Default constructor" << std::endl;
}

Animal::Animal(const Animal& animal)
    : mType(animal.GetType())
{
    std::cout << "Animal Copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "Animal Assignation operator" << std::endl;
    if (this != &animal)
        mType = animal.GetType();
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor" << std::endl;
}

std::string Animal::GetType() const
{
    return (mType);
}

void Animal::SetType(std::string type)
{
    mType = type;
}

