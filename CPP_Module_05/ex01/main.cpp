#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test 1: Form Constructors and Exception Handling
    std::cout << "Test 1: Form Constructors and Exception Handling\n";
    try {
        Form f1("Form1", 0, 50);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f2("Form2", 50, 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f3("Form3", 50, 50);
        std::cout << f3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-------------------\n";

    // Test 2: beSigned Method and signForm Method
    std::cout << "Test 2: beSigned Method and signForm Method\n";
    Bureaucrat b1("Munsan", 20);
    Bureaucrat b2("Guryongpo", 60);
	Form f4("Form5", 30, 30);
	Form f5("Form6", 30, 30);

    b1.SignForm(f4);
    b1.SignForm(f4);
	b2.SignForm(f5);
    std::cout << "-------------------\n";
    return 0;
}
