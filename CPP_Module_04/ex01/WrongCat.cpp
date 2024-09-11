#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal()
{
    mType = "WrongCat";
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
    : WrongAnimal()
{
    mType = wrongCat.GetType();
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    if (this != &wrongCat)
    {
        WrongAnimal::operator=(wrongCat);
        mType = wrongCat.GetType();
    }
    std::cout << "WrongCat assignation operator" << std::endl;
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
