#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact()
{
	mFirstname = "";
	mLastname = "";
	mNickname = "";
	mPhonenumber = "";
	mDarkestsecret = "";
}

Contact::~Contact()
{
}

void	Contact::SetFirstName(std::string firstName)
{
	mFirstname = firstName;
}

void	Contact::SetLastName(std::string lastName)
{
	mLastname = lastName;
}

void	Contact::SetNickName(std::string nickName)
{
	mNickname = nickName;
}

void	Contact::SetPhoneNumber(std::string phoneNumber)
{
	mPhonenumber = phoneNumber;
}

void	Contact::SetDarkestSecret(std::string darkestSecret)
{
	mDarkestsecret = darkestSecret;
}

std::string	Contact::GetFirstName() const
{
	return (mFirstname);
}

std::string	Contact::GetLastName() const
{
	return (mLastname);
}

std::string	Contact::GetNickName() const
{
	return (mNickname);
}

std::string	Contact::GetPhoneNumber() const
{
	return (mPhonenumber);
}

std::string	Contact::GetDarkestSecret() const
{
	return (mDarkestsecret);
}
