#include <iostream>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}

	std::string inputString;
	for (int index = 1; index < argc; index++)
	{
		inputString += argv[index];
	}

	for (int index = 0; inputString[index] != '\0'; index++)
	{
		inputString[index] = static_cast<char>(std::toupper(inputString[index]));
	}
	std::cout << inputString << std::endl;
	return (0);
}