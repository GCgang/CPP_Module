#include "Bureaucrat.hpp"

int main() {	
    // Test 1: Default Constructor
    std::cout << "Test 1: Default Constructor\n";
    try {
        Bureaucrat b1;
        std::cout << b1 << std::endl;
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------\n";
    
    // Test 2: Parameterized Constructor and Exception Handling
    std::cout << "Test 2: Parameterized Constructor and Exception Handling\n";
    try {
        Bureaucrat b2("Guryongpo", 150);
        std::cout << b2 << std::endl;
    } catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Munsan", 0);
        std::cout << b3 << std::endl;
    } catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------\n";

    // Test 3: Copy Constructor
    std::cout << "Test 3: Copy Constructor\n";
    try {
        Bureaucrat b4("Mihyeon", 50);
        Bureaucrat b5(b4);
        std::cout << b5 << std::endl;
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------\n";

    // Test 4: Assignment Operator
    std::cout << "Test 4: Assignment Operator\n";
    try {
        Bureaucrat b6("Bongseok", 20);
        Bureaucrat b7("Hee-su", 40);
        b7 = b6;
        std::cout << b7 << std::endl;
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------\n";

    // Test 5: Grade Increment/Decrement and Exception Handling
    std::cout << "Test 5: Grade Increment/Decrement and Exception Handling\n";
    try {
        Bureaucrat b8("KangHoon", 2);
        b8.IncrementGrade();
        std::cout << b8 << std::endl;
        b8.IncrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b9("BGman", 149);
        b9.DecrementGrade();
        std::cout << b9 << std::endl;
        b9.DecrementGrade();
    } catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------\n";

    // Test 6: Grade Increment/Decrement Overloading
    std::cout << "Test 6: Grade Increment/Decrement Overloading\n";
    try {
        Bureaucrat b10("Frank", 10);
        b10.IncrementGrade(4);
        std::cout << b10 << std::endl;
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b11("Min", 149);
        b11.DecrementGrade(-1);
        std::cout << b11 << std::endl;
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
    } 

    try {
        Bureaucrat b12("Il-hwan", 149);
        b12.DecrementGrade(-1);
        std::cout << b12 << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
    } catch (...)
	{
    	std::cerr << "An unknown error occurred" << std::endl;
	}
    std::cout << "-------------------\n";

    return 0;
}
