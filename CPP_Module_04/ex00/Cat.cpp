#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
    : Animal()
{
    std::cout << "Cat default constructor" << std::endl;
    mType = "Cat";
}

Cat::Cat(const Cat& cat)
    : Animal(cat)
{
    std::cout << "Cat copy constructor" << std::endl;
    mType = cat.GetType();
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat assignation operator" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
        mType = cat.GetType();
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

void Cat::MakeSound() const
{
    std::cout << "Meow~ Meow~" << std::endl;
}