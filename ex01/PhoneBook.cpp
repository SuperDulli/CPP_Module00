#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void): contactCount(0) {
	std::cout << "Default PhoneBook Constuctor called" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook& pB): contactCount(pB.contactCount) {
	std::cout << "Copy PhoneBook Constuctor called" << std::endl;

	std::cout << "copy all the contacts over" << std::endl;
	for (size_t i = 0; i < this->contactCount; i++) {
		this->contacts[i] = pB.contacts[i];
	}
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destuctor called" << std::endl;
}

void	PhoneBook::add(const Contact& c) {
	const size_t	i = this->contactCount % 8;
	this->contacts[i] = c;
	this->contactCount++;
	std::cout << "Contact added at index:" << i << std::endl;
}
