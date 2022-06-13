#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Default Contact Constuctor called" << std::endl;
}

Contact::Contact(const Contact& c):
	firstName(c.firstName),
	lastName(c.lastName),
	nickname(c.nickname),
	phoneNumber(c.phoneNumber),
	secret(c.secret) {
	std::cout << "Copy Contact Constuctor called" << std::endl;
}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string secret) :
	firstName(firstName),
	lastName(lastName),
	nickname(nickname),
	phoneNumber(phoneNumber),
	secret(secret) {
	std::cout << "Contact Constuctor called" << std::endl;
}

Contact::~Contact(void) {
	std::cout << "Contact Destructor called" << std::endl;
}

Contact&	Contact::operator=(const Contact& c) {
	std::cout << "Contact Assignment operator called" << std::endl;
	firstName = c.getFirstName();
	lastName = c.getLastName();
	nickname = c.getNickname();
	//TODO: do the copy
	return *this;
}

std::string	Contact::getFirstName(void) const {
	return this->firstName;
}

std::string	Contact::getLastName(void) const {
	return this->lastName;
}

std::string	Contact::getNickname(void) const {
	return this->nickname;
}

std::string	Contact::getPhoneNumber(void) const {
	return this->phoneNumber;
}

std::string	Contact::getSecret(void) const {
	return this->secret;
}

