#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : mType("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
    : mType(wrongAnimal.GetType())
{
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal assignation operator" << std::endl;
    if (this != &wrongAnimal)
        mType = wrongAnimal.GetType();
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::MakeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::GetType() const
{
    return (mType);
}

void WrongAnimal::SetType(std::string type)
{
    mType = type;
}