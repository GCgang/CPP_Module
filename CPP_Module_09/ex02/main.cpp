#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe pmergeMe;

	try
	{
		pmergeMe.IsValidInput(argc, argv);
		pmergeMe.SortUsingContainer();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (1);
}
