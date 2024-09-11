#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void leaks(void)
// {
//     system("leaks polymorphism");
// }

int main()
{
	// atexit(leaks);
    Animal animal;
	std::cout << std::endl;
    Dog dog;
	std::cout << std::endl;
    Cat cat;
	std::cout << std::endl;
    Animal* pAnimal = new Animal();
	std::cout << std::endl;
    Animal* pDog = new Dog();
	std::cout << std::endl;
    Animal* pCat = new Cat();
    std::cout << std::endl;

    animal.MakeSound();
    std::cout << std::endl;
    dog.MakeSound();
    std::cout << std::endl;
    cat.MakeSound();
    std::cout << std::endl;

    pAnimal->MakeSound();
    std::cout << std::endl;
    pDog->MakeSound();
    std::cout << std::endl;
    pCat->MakeSound();
    std::cout << std::endl;

    std::cout << "Animal type: " << animal.GetType() << std::endl;
    std::cout << "Dog type: " << dog.GetType() << std::endl;
    std::cout << "Cat type: " << cat.GetType() << std::endl;
    std::cout << "pAnimal type: " << pAnimal->GetType() << std::endl;
    std::cout << "pDog type: " << pDog->GetType() << std::endl;
    std::cout << "pCat type: " << pCat->GetType() << std::endl;
    std::cout << std::endl;
    delete pAnimal;
	std::cout << std::endl;
    delete pDog;
	std::cout << std::endl;
    delete pCat;
	std::cout << std::endl;


    WrongAnimal wrongAnimal;
	std::cout << std::endl;
    WrongCat wrongCat;
	std::cout << std::endl;
    WrongAnimal* pWrongAnimal = new WrongAnimal();
	std::cout << std::endl;
    WrongAnimal* pWrongCat = new WrongCat();
    std::cout << std::endl;

    wrongAnimal.MakeSound();
    std::cout << std::endl;
    wrongCat.MakeSound();
    std::cout << std::endl;

    pWrongAnimal->MakeSound();
    std::cout << std::endl;
    pWrongCat->MakeSound();
    std::cout << std::endl;

    std::cout << "WrongAnimal type: " << wrongAnimal.GetType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat.GetType() << std::endl;
    std::cout << "pWrongAnimal type: " << pWrongAnimal->GetType() << std::endl;
    std::cout << "pWrongCat type: " << pWrongCat->GetType() << std::endl;
    std::cout << std::endl;
    delete pWrongAnimal;
	std::cout << std::endl;
    delete pWrongCat;
	std::cout << std::endl;

    return 0;
}
