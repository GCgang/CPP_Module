#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	mInformationMessage[FirstName] = "First Name : ";
	mInformationMessage[LastName] = "Last Name : ";
	mInformationMessage[NickName] = "NickName : ";
	mInformationMessage[PhoneNumber] = "Phone Number : ";
	mInformationMessage[DarkestSecret] = "Darkest Secret : ";
	mIndex = 0;
	mInformationCount = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::Add()
{
	SetInputInformation();
	SetContactList();
	SetIndex();
	SetInformationCount();
}

void	PhoneBook::Search(void) const
{
	DisplaySaveContactInformation();
	DisplayAdditionalContactInformationAtIndex(GetValidIndex());
}

void	PhoneBook::Exit(int exitStatus) const
{
	exit(exitStatus);
}

void	PhoneBook::SetInputInformation()
{
	for (int informationIndex = 0; informationIndex < MAX_CONTACT_INFO; informationIndex++)
	{
		std::cout << GetInformationMessage(informationIndex);
		std::getline(std::cin, mInputInformation[informationIndex]);
		if (std::cin.eof() == true)
		{
			Exit(ERROR_CODE);
		}
		else if (IsEmptyField(mInputInformation[informationIndex]) == true)
		{
			std::cerr << "Contact information cannot be empty. Please try again" << std::endl;
			informationIndex--;
		}
	}
}

void	PhoneBook::SetContactList()
{
	mContactList[GetIndex()].SetFirstName(mInputInformation[FirstName]);
	mContactList[GetIndex()].SetLastName(mInputInformation[LastName]);
	mContactList[GetIndex()].SetNickName(mInputInformation[NickName]);
	mContactList[GetIndex()].SetPhoneNumber(mInputInformation[PhoneNumber]);
	mContactList[GetIndex()].SetDarkestSecret(mInputInformation[DarkestSecret]);
}

void	PhoneBook::SetIndex()
{
	if (mIndex == 7)
	{
		mIndex = 0;
	}
	else
	{
		mIndex++;
	}
}

void	PhoneBook::SetInformationCount()
{
	if (mInformationCount == 8)
	{
		return ;	
	}
	else
	{
		mInformationCount++;
	}
}

void	PhoneBook::DisplaySaveContactInformation(void) const
{
	int lineSize = (((WIDTH * MAX_COLUMN) + SEPARATOR_COUNT));
	DisplayLine(lineSize);
	std::cout << "|" << std::setw(WIDTH) << std::right << "INDEX";
	std::cout << "|" << std::setw(WIDTH) << std::right << "FIRSTNAME";
	std::cout << "|" << std::setw(WIDTH) << std::right << "LASTNAME";
	std::cout << "|" << std::setw(WIDTH) << std::right << "NICKNAME";
	std::cout << "|" << std::endl;
	for (int index = 0; index < GetInformationCount(); index++)
	{
		std::cout << "|" << std::setw(WIDTH) << std::right << index + 1;
		std::cout << "|" << std::setw(WIDTH) << std::right << GetDisplayName(mContactList[index].GetFirstName());
		std::cout << "|" << std::setw(WIDTH) << std::right << GetDisplayName(mContactList[index].GetLastName());
		std::cout << "|" << std::setw(WIDTH) << std::right << GetDisplayName(mContactList[index].GetNickName());
		std::cout << "|" << std::endl;
	}
	DisplayLine(lineSize);
}

void	PhoneBook::DisplayLine(const int lineSize) const
{
	for (int i = 0; i < lineSize; i++)
	{
		if (i == 0 || i == (lineSize - 1))
			std::cout << '+';
		else
			std::cout << '-';
	}
	std::cout << std::endl;
}

std::string PhoneBook::GetDisplayName(std::string name) const
{
	std::string displayName = name;
	if (WIDTH <= static_cast<int>(displayName.size()))
	{
		displayName[WIDTH - 1] = '.';
	}
	for (int index = WIDTH; index < static_cast<int>(displayName.size()); index++)
	{
		displayName[index] = '\0';
	}
	
	return displayName;
}

void	PhoneBook::DisplayAdditionalContactInformationAtIndex(int index) const
{
	if (IsEmptyField(mContactList[index - 1].GetFirstName()) == true)
	{
		std::cerr << "Unable to find contact information for the entered index. Please try again" << std::endl;
		return ;
	}
	std::cout << std::setw(MAX_WIDTH) << std::left << "INDEX" << ": ";
	std::cout << index << std::endl;
	std::cout << std::setw(MAX_WIDTH) << std::left << "FIRSTNAME" << ": ";
	std::cout << mContactList[index - 1].GetFirstName() << std::endl;
	std::cout << std::setw(MAX_WIDTH) << std::left << "LASTNAME" << ": ";
	std::cout << mContactList[index - 1].GetLastName() << std::endl;
	std::cout << std::setw(MAX_WIDTH) << std::left << "NICKNAME" << ": ";
	std::cout << mContactList[index - 1].GetNickName() << std::endl;
	std::cout << std::setw(MAX_WIDTH) << std::left << "PHONENUMBER" << ": ";
	std::cout << mContactList[index - 1].GetPhoneNumber() << std::endl;
	std::cout << std::setw(MAX_WIDTH) << std::left << "DARKESTSECRET" << ": ";
	std::cout << mContactList[index - 1].GetDarkestSecret() << std::endl;
}

int	PhoneBook::GetIndex(void) const
{
	return (mIndex);
}

int	PhoneBook::GetInformationCount(void) const
{
	return (mInformationCount);
}

int	PhoneBook::GetValidIndex(void) const
{
	int validIndex;

	while (true)
	{
		std::cout << "Please enter the index for additional contact information : ";
		std::cin >> validIndex;
		if (std::cin.eof() == true)
		{
			Exit(ERROR_CODE);
		}
		if (1 <= validIndex && validIndex <= 8)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
		else
		{
			std::cerr << "Index out of range or wrong.(Valid range is 1 to 8)" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return (validIndex);
}

std::string PhoneBook::GetInformationMessage(int informationIndex) const
{
	return (mInformationMessage[informationIndex]);
}

bool	PhoneBook::IsEmptyField(std::string information) const
{
	if (information.empty() == true)
	{
		return (true);
	}
	for (size_t i = 0; i < information.length(); i++)
	{
		if (std::isspace(static_cast<int>(information[i])) == false)
		{
			return (false);
		}
	}
    return (true);
}