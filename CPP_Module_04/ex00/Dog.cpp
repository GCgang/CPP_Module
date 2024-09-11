#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
    : Animal()
{
    std::cout << "Dog default constructor" << std::endl;
    mType = "Dog";
}

Dog::Dog(const Dog& dog)
    : Animal(dog)
{
    std::cout << "Dog copy constructor" << std::endl;
    mType = dog.GetType();
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog assignation operator" << std::endl;
    if (this != &dog)
    {
        Animal::operator=(dog);
        mType = dog.GetType();
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

void Dog::MakeSound() const
{
    std::cout << "Bark Bark !" << std::endl;
}
