#pragma once
#ifndef	CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
class PhoneBook;

class Contact
{
	public:
		Contact();
		~Contact();
		void	SetFirstName(std::string firstName);
		void	SetLastName(std::string lastName);
		void	SetNickName(std::string nickName);
		void	SetPhoneNumber(std::string phoneNumber);
		void	SetDarkestSecret(std::string darkestSecret);
		std::string	GetFirstName(void) const;
		std::string	GetLastName(void) const;
		std::string	GetNickName(void) const;
		std::string	GetPhoneNumber(void) const;
		std::string	GetDarkestSecret(void) const;
	private:
		std::string mFirstname;
		std::string mLastname;
		std::string mNickname;
		std::string mPhonenumber;
		std::string mDarkestsecret;
};

#endif // CONTACT_HPP