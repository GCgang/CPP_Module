#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>

class Contact;

#define ERROR_CODE (1)
#define MAX_CONTACT (8)
#define MAX_CONTACT_INFO (5)
#define WIDTH (10)
#define MAX_WIDTH (14)
#define MAX_COLUMN (4)
#define SEPARATOR_COUNT (5)

enum eInformation
{
	FirstName,
	LastName,
	NickName,
	PhoneNumber,
	DarkestSecret
};

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void		Add(void);
		void		Search(void) const;
		void		Exit(int exitStatus) const;
		void		SetInputInformation(void);
		void		SetContactList(void);
		void		SetIndex(void);
		void		SetInformationCount(void);
		void		DisplaySaveContactInformation(void) const;
		void		DisplayLine(const int lineSize) const;
		void		DisplayAdditionalContactInformationAtIndex(int index) const;
		int			GetIndex(void) const;
		int			GetInformationCount(void) const;
		int			GetValidIndex(void) const;
		std::string GetInformationMessage(int informationIndex) const;
		std::string	GetDisplayName(std::string name) const;
		bool		IsEmptyField(std::string information) const;
	private:
		Contact mContactList[MAX_CONTACT];
		std::string mInputInformation[MAX_CONTACT_INFO];
		std::string mInformationMessage[MAX_CONTACT_INFO];
		int	mIndex;
		int	mInformationCount;
};

#endif // PHONEBOOK_HPP