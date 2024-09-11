#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert [inputString]" << std::endl;
        return 1;
    }
    ScalarConverter::Convert(argv[1]);
    return 0;
}