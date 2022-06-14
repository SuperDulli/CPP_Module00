#include <iostream>
#include <ctype.h>
#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Default Contact Constuctor called" << std::endl;
}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string secret) {
	std::cout << "Contact Constuctor called" << std::endl;
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setNickname(nickname);
	this->setPhoneNumber(phoneNumber);
	this->setSecret(secret);
}

Contact::~Contact(void) {
	std::cout << "Contact Destructor called for " << this->m_nickname << std::endl;
}

std::string	Contact::getFirstName(void) const { return this->m_firstName; }

std::string	Contact::getLastName(void) const { return this->m_lastName; }

std::string	Contact::getNickname(void) const { return this->m_nickname; }

std::string	Contact::getPhoneNumber(void) const { return this->m_phoneNumber; }

std::string	Contact::getSecret(void) const { return this->m_secret; }

bool		Contact::setFirstName(std::string firstName) {
	if (firstName.length() == 0) {
		std::cerr << "first name cannot be empty" << std::endl;
		return false;
	}
	else if (isdigit(firstName.at(0))) {
		std::cerr << "first name cannot begin with a digit" << std::endl;
		return false;
	}
	this->m_firstName = firstName;
	return true;
}

bool		Contact::setLastName(std::string lastName) {
	if (lastName.length() == 0) {
		std::cerr << "last name cannot be empty" << std::endl;
		return false;
	}
	else if (isdigit(lastName.front())) {
		std::cerr << "last name cannot begin with a digit" << std::endl;
		return false;
	}
	this->m_lastName = lastName;
	return true;
}

bool		Contact::setNickname(std::string nickname) {
	// std::cout << "Contact::setNickname called" << std::endl;
	if (nickname.length() == 0) {
		std::cerr << "nickname cannot be empty" << std::endl;
		return false;
	}
	this->m_nickname = nickname;
	return true;
}

bool		Contact::setPhoneNumber(std::string phoneNumber) {
	if (Contact::isValidPhoneNunmber(phoneNumber)) {
		this->m_phoneNumber = phoneNumber;
		return true;
	}
	return false;
}

bool		Contact::setSecret(std::string secret) {
	this->m_secret = secret;
	return true;
}

bool	Contact::isValidPhoneNunmber(std::string phoneNumber) {
	if (phoneNumber.length() == 0) {
		std::cerr << "phone number cannot be empty" << std::endl;
		return false;
	}
	else if (!isdigit(phoneNumber.front()) && phoneNumber.front() != '+') {
		std::cerr << "phone number has to start with a digit or +" << std::endl;
		return false;
	}
	else if (phoneNumber.find_first_not_of(" +1234567890") != std::string::npos) {
		std::cerr << "phone number contains unsupported character(s)" << std::endl;
		return false;
	}
	return true;
}
