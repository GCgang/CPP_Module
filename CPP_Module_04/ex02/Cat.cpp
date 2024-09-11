#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
    : Animal()
    , mBrain(NULL)
{
    std::cout << "Cat default constructor" << std::endl;
    mType = "Cat";
    mBrain = new Brain();
}

Cat::Cat(const Cat& cat)
    : Animal(cat)
    , mBrain(NULL)
{
    std::cout << "Cat copy constructor" << std::endl;
    mType = cat.GetType();
    mBrain = new Brain(*cat.GetBrain());
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat assignation operator" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
        mType = cat.GetType();
        delete mBrain;
        mBrain = new Brain(*cat.GetBrain());
    }
    return (*this);
}

Cat::~Cat()
{
    delete mBrain;
    std::cout << "Cat destructor" << std::endl;
}

void Cat::MakeSound() const
{
    std::cout << "Meow~ Meow~" << std::endl;
}

const Brain* Cat::GetBrain() const
{
    if (mBrain == NULL)
        return (NULL);
    return (mBrain);
}