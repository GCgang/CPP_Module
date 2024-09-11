#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// void leaks(void)
// {
// 	system("leaks brain");
// }

int main()
{
    // atexit(leaks);

    const Animal* j = new Dog();
	std::cout << std::endl;
    const Animal* i = new Cat();
	std::cout << std::endl;
    delete j;
	std::cout << std::endl;
    delete i;
	std::cout << std::endl;

    const int animalCount = 10;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount / 2; i++)
    {
		std::cout << "i = " << i << std::endl;
        animals[i] = new Dog();
		std::cout << std::endl;
		std::cout << "i + animalCount / 2 = " << i + animalCount / 2 << std::endl;
        animals[i + animalCount / 2] = new Cat();
		std::cout << std::endl;
    }

    for (int i = 0; i < animalCount; i++)
    {
        animals[i]->MakeSound();
    }
	std::cout << std::endl;

    for (int i = 0; i < animalCount; i++)
    {
        delete animals[i];
		std::cout << std::endl;
    }
	std::cout << std::endl;

    Dog dog1;
	std::cout << std::endl;
    dog1.SetType("Golden Retriever");
    dog1.GetBrain()->InitializeIdeas();
    Dog dog2 = dog1;
    dog2.SetType("Samoyed");
	std::cout << std::endl;

    Cat cat1;
	std::cout << std::endl;
    cat1.SetType("Persian");
    cat1.GetBrain()->InitializeIdeas();
    Cat cat2 = cat1;
    cat2.SetType("munchkin");
	std::cout << std::endl;

    std::cout << "Dog 1 Type: " << dog1.GetType() << std::endl;
	std::cout << std::endl;
    dog1.GetBrain()->PrintIdeas();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Dog 2 Type: " << dog2.GetType() << std::endl;
	std::cout << std::endl;
    dog2.GetBrain()->PrintIdeas();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Cat 1 Type: " << cat1.GetType() << std::endl;
	std::cout << std::endl;
    cat1.GetBrain()->PrintIdeas();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Cat 2 Type: " << cat2.GetType() << std::endl;
	std::cout << std::endl;
    cat2.GetBrain()->PrintIdeas();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "dog1 Brain address: " << dog1.GetBrain() << std::endl;
    std::cout << "dog2 Brain address: " << dog2.GetBrain() << std::endl;
    std::cout << "cat1 Brain address: " << cat1.GetBrain() << std::endl;
    std::cout << "cat2 Brain address: " << cat2.GetBrain() << std::endl;

    return 0;
}