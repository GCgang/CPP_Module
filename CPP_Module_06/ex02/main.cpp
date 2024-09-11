#include "Identify.hpp"

// void leaks(void)
// {
// 	system("leaks Dynamic_Cast");
// }

int main()
{   
	// atexit(leaks);

    Base *base = Generate();
	if (base != NULL)
	{
    	Identify(base);
    	Identify(*base);
	}

	delete base;
	return (0);
}