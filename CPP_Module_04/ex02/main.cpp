#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// void leaks(void)
// {
// 	system("leaks abstract");
// }

int main()
{
	// atexit(leaks);

    // Animal myAnimal;
    // Dog myDog;
    // Animal* animal = new Animal();
    Animal* animal = new Dog();
	std::cout << std::endl;
    animal->MakeSound();
	std::cout << std::endl;
    delete animal;
    return 0;
}