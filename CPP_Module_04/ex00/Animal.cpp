#include "Animal.hpp"

Animal::Animal()
    : mType("Animal")
{
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& animal)
    : mType(animal.GetType())
{
    std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "Animal assignation operator" << std::endl;
    if (this != &animal)
        mType = animal.GetType();
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

void Animal::MakeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::GetType() const
{
    return (mType);
}

void Animal::SetType(std::string type)
{
    mType = type;
}
