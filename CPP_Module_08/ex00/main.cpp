#include "EasyFind.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <list>

int main()
{
    /* =================== Initialize =================== */
	std::srand(static_cast<unsigned>(std::time(NULL)));

    std::deque<int> dequeContainer;
    std::vector<int> vectorContainer;
    std::list<int> listContainer;

    const int numElements = 10;

    for (int i = 0; i < numElements; ++i) {
        int randomValue = std::rand() % 10;
        dequeContainer.push_back(randomValue);
        vectorContainer.push_back(randomValue);
        listContainer.push_back(randomValue);
    }

    /* =================== vector test =================== */
    try
    {
        std::vector<int>::iterator vIt = easyFind(vectorContainer, 1);
        std::ptrdiff_t position = std::distance(vectorContainer.begin(), vIt);

        std::cout << "Value : " << *vIt << std::endl;
        std::cout << "Positon : " << position << std::endl;
        printContainer(vectorContainer, "vector");
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    /* =================== deque test =================== */
    try 
    {
        std::deque<int>::iterator dIt = easyFind(dequeContainer, 11);
        std::ptrdiff_t position = std::distance(dequeContainer.begin(), dIt);
    
        std::cout << "Value : " << *dIt << std::endl;
        std::cout << "Positon : " << position << std::endl;
        printContainer(dequeContainer, "deque");
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    /* =================== list test =================== */
    try
    {
        std::list<int>::iterator lIt = easyFind(listContainer, 5);
        std::ptrdiff_t position = std::distance(listContainer.begin(), lIt);

        std::cout << "Value : " << *lIt << std::endl;
        std::cout << "Positon : " << position << std::endl;
        printContainer(listContainer, "list");
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
	// std::cout << std::endl;
    // /* =================== const version test =================== */
    // try
    // {
	// 	const int numElements = 10;
	// 	const std::vector<int> constVectorContainer(numElements, 1);
    //     std::vector<int>::const_iterator cvIt = easyFind(constVectorContainer, 1);
        

    //     // Attempt to modify the value. This should result in a compilation error.
    //     *cvIt = 99;  // This line will cause a compile-time error
	// 	// static_cast<void>(cvIt);
	// 	// printContainer(constVectorContainer, "constVector");
    // }
    // catch (std::exception& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

}