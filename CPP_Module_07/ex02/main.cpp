#include <iostream>
#include "Array.hpp"
#include <cstdlib> 
#include <ctime> 

#define MAX_VAL 750

// void leaks(void)
// {
// 	system("leaks Array");
// }

int main(int, char**)
{
	// atexit(leaks);

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// #include <iostream>
// #include "Array.hpp"

// int main()
// {
// 	atexit(leaks);

//     // 1. Testing default constructor
//     Array<int> defaultArray;
//     std::cout << "Size of defaultArray: " << defaultArray.Size() << std::endl; // Expected: Size of defaultArray: 0

//     // 2. Testing constructor with size argument
//     Array<int> customSizeArray(5);
//     std::cout << "Size of customSizeArray: " << customSizeArray.Size() << std::endl; // Expected: Size of customSizeArray: 5

//     // 3. Testing copy constructor
//     Array<int> copiedArray(customSizeArray);
//     std::cout << "Size of copiedArray: " << copiedArray.Size() << std::endl; // Expected: Size of copiedArray: 5

//     // Checking deep copy
//     customSizeArray[0] = 42;
//     std::cout << "customSizeArray[0]: " << customSizeArray[0] << ", copiedArray[0]: " << copiedArray[0] << std::endl; // Expected: customSizeArray[0]: 42, copiedArray[0]: 0

//     // 4. Testing copy assignment operator
//     Array<int> assignedArray;
//     assignedArray = customSizeArray;
//     std::cout << "Size of assignedArray: " << assignedArray.Size() << std::endl; // Expected: Size of assignedArray: 5

//     // Checking deep copy
//     customSizeArray[0] = 100;
//     std::cout << "customSizeArray[0]: " << customSizeArray[0] << ", assignedArray[0]: " << assignedArray[0] << std::endl; // Expected: customSizeArray[0]: 100, assignedArray[0]: 42

//     // 5. Testing [] operator overloading
//     try 
//     {
//         assignedArray[10] = 55;  // Out-of-range index
//     }
//     catch (const std::exception& e) 
//     {
//         std::cerr << "Exception: " << e.what() << std::endl; // Expected: Exception: Array index is out of bounds!
//     }
    
//     try 
//     {
//         std::cout << "assignedArray[3]: " << assignedArray[3] << std::endl;  // Within range index // Expected: assignedArray[3]: 0
//     }
//     catch (const std::exception& e) 
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     // 6. Testing const [] operator overloading
//     const Array<int> constArray(5);
//     try 
//     {
//         std::cout << "constArray[2]: " << constArray[2] << std::endl;  // Within range index // Expected: constArray[2]: 0
//     }
//     catch (const std::exception& e) 
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     try 
//     {
//         std::cout << "constArray[7]: " << constArray[7] << std::endl;  // Out-of-range index
//     }
//     catch (const std::exception& e) 
//     {
//         std::cerr << "Exception: " << e.what() << std::endl; // Expected: Exception: Array index is out of bounds!
//     }

//     // 7. Testing Size() function
//     std::cout << "Size of constArray: " << constArray.Size() << std::endl; // Expected: Size of constArray: 5

//     // 8. Testing various template types
//     Array<double> doubleArray(3);
//     doubleArray[0] = 1.1;
//     doubleArray[1] = 2.2;
//     doubleArray[2] = 3.3;

//     std::cout << "doubleArray elements: ";
//     for(unsigned int i = 0; i < doubleArray.Size(); ++i)
//     {
//         std::cout << doubleArray[i] << " "; // Expected: doubleArray elements: 1.1 2.2 3.3
//     }
//     std::cout << std::endl;

//     return 0;
// }
