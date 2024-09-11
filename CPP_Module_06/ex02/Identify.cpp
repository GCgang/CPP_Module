#include "Identify.hpp"

Base *Generate()

{
	std::time_t currentTime;

	std::time(&currentTime);
	srand(currentTime);

	int randomValue = rand() % 3;
	if (randomValue == 0)
	{
		std::cout << "Generate A" << std::endl;
		return new A();
	}
	else if (randomValue == 1)
	{
		std::cout << "Generate B" << std::endl;
		return new B();
	}
	else if (randomValue == 2)
	{
		std::cout << "Generate C" << std::endl;
		return new C();
	}
    return (NULL);
}


void IdentifyPointer(Base *p, const std::string& type)
{
    if (type == "A" && dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "Pointer A" << std::endl;
    }
    else if (type == "B" && dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "Pointer B" << std::endl;
    }
    else if (type == "C" && dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "Pointer C" << std::endl;
    }
    else
    {
        std::cerr << "Pointer ";
		std::cerr << type;
		std::cerr << " failed" << std::endl;
    }
}

void Identify(Base *p)
{
    IdentifyPointer(p, "A");
    IdentifyPointer(p, "B");
    IdentifyPointer(p, "C");
}

void IdentifyReference(Base &p, const std::string type)
{
    try
    {
        if (type == "A")
        {
            (void)dynamic_cast<A&>(p);
        }
		if (type == "B")
        {
            (void)dynamic_cast<B&>(p);
        }
		if (type == "C")
        {
            (void)dynamic_cast<C&>(p);
        }

    std::cout << "Reference " << type << std::endl;
    }
    catch (std::exception &)
    {
        std::cerr << "Reference ";
        std::cerr << type;
        std::cerr << " failed" << std::endl;
    }
}

void Identify(Base &p)
{
    IdentifyReference(p, "A");
    IdentifyReference(p, "B");
    IdentifyReference(p, "C");
}
