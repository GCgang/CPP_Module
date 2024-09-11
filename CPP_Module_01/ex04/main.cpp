#include <iostream>
#include "FileReplacer.hpp"

int main(int argc, char **argv)
{
	FileReplacer	FileReplacer;
	if (argc != 4)
	{
		std::cerr << GetError(ERROR_ARGC) << std::endl;
		return (1);
	}
	else if (FileReplacer.IsValidFileName(std::string(argv[1])) == false)
	{
		return (1);
	}
	else if (FileReplacer.IsValidStrings(std::string(argv[2]), std::string(argv[3])) == false)
	{
		return (1);
	}
	else if (FileReplacer.ReplaceFile() == false)
	{
		return (1);
	}
	return (0);
}
