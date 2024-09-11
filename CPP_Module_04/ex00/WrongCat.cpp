#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal()
{
    std::cout << "WrongCat default constructor" << std::endl;
    mType = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrongCat)
    : WrongAnimal()
{
    std::cout << "WrongCat copy constructor" << std::endl;
    mType = wrongCat.GetType();
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    std::cout << "WrongCat assignation operator" << std::endl;
    if (this != &wrongCat)
    {
        WrongAnimal::operator=(wrongCat);
        mType = wrongCat.GetType();
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::MakeSound() const
{
    std::cout << "Wrong Meow~ Wrong Meow~" << std::endl;
}
