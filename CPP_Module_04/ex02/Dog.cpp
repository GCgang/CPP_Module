#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
    : Animal()
    , mBrain(NULL)
{
    std::cout << "Dog default constructor" << std::endl;
    mType = "Dog";
    mBrain = new Brain();
}

Dog::Dog(const Dog& dog)
    : Animal(dog)
    , mBrain(NULL)
{
    std::cout << "Dog copy constructor" << std::endl;
    mType = dog.GetType();
    mBrain = new Brain(*dog.GetBrain());
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog assignation operator" << std::endl;
    if (this != &dog)
    {
        Animal::operator=(dog);
        mType = dog.GetType();
        delete mBrain;
        mBrain = new Brain(*dog.GetBrain());
    }
    return (*this);
}

Dog::~Dog()
{
    delete mBrain;
    std::cout << "Dog destructor" << std::endl;
}

void Dog::MakeSound() const
{
    std::cout << "Bark Bark !" << std::endl;
}

const Brain* Dog::GetBrain() const
{
    if (mBrain == NULL)
        return (NULL);
    return (mBrain);
}