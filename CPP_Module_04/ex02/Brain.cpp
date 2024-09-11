#include "Brain.hpp"

Brain::Brain()
	: mIdeas(NULL)
{
	std::cout << "Brain default constructor" << std::endl;
	mIdeas = new std::string[IDEA_COUNT];
	InitializeIdeas();
}

Brain::Brain(const Brain& brain)
	: mIdeas(NULL)
{
	std::cout << "Brain copy constructor" << std::endl;
	mIdeas = new std::string[IDEA_COUNT];
	for (int i = 0; i < IDEA_COUNT; i++)
	{
		mIdeas[i] = brain.mIdeas[i];
	}
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "Brain assignation operator" << std::endl;
	if (this != &brain)
	{
		delete[] mIdeas;
		mIdeas = new std::string[IDEA_COUNT];
		for (int i = 0; i < IDEA_COUNT; i++)
		{
			mIdeas[i] = brain.mIdeas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	delete[] mIdeas;
	std::cout << "Brain destructor" << std::endl;
}

void	Brain::InitializeIdeas() const
{
	std::ifstream inPutFile;
	inPutFile.open("3.5ideas.txt");
	if (!inPutFile.is_open())
	{
		std::cerr << "Error: File opening failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string ideaTable[IDEA_COUNT];
	std::string line;
	int ideaCount = 0;
	while (std::getline(inPutFile, line) && ideaCount < IDEA_COUNT)
	{
		ideaTable[ideaCount++] = line;
	}

	// Shuffle the ideas
	srand(time(NULL)); // Seed the random number generator

	for (int index = 0; index < IDEA_COUNT; index++)
	{
		int randomIndex = rand() % ideaCount; // Random index in the range [0, ideaCount - 1]
		mIdeas[index] = ideaTable[randomIndex];
	}
	inPutFile.close();
}

void Brain::PrintIdeas() const
{
	for (int i = 0; i < IDEA_COUNT; i++)
	{
		std::cout << mIdeas[i] << std::endl;
	}
}