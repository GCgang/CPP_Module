#include "RPN.hpp"

int main (int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid Argument" << std::endl;
		return (1);
	}

    try
    {
        double result = RPN::Calculate(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    return (0);
}