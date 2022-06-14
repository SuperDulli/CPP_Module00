#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

typedef bool (Contact::* Csetter)(std::string);
typedef std::string(Contact::* Cgetter)(void) const;

PhoneBook::PhoneBook(void) : m_contactCount(0) {
	std::cout << "Default PhoneBook Constuctor called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destuctor called" << std::endl;
}

void	PhoneBook::add(void) {
	std::cout << "ADD Contact. Please provide info about the contact" << std::endl;

	const size_t		insertPos = this->m_contactCount % 8;
	const std::string	hints[] = { "first name: ", "last name: ", "nickname: ", "phone number: ", "secret: " };
	const Csetter		setters[] = { &Contact::setFirstName, &Contact::setLastName, &Contact::setNickname, &Contact::setPhoneNumber, &Contact::setSecret };
	const size_t		hintCount = 5;
	std::string			input;
	bool				success = false;
	size_t				failed_attempts = 0;
	size_t				i = 0;

	while (i < hintCount && failed_attempts <= 3)
	{
		std::cout << hints[i];
		std::cin >> input;
		success = (this->m_contacts[insertPos].*setters[i])(input);
		if (!success) {
			failed_attempts++;
			continue;
		}
		if (success) {
			success = false;
			failed_attempts = 0;
			i++;
		}
	}
	if (failed_attempts) {
		std::cerr << "Contact not added" << std::endl;
		return;
	}
	// this->m_contacts[insertPos] = c;
	this->m_contactCount++;
	std::cout << "Contact added at index:" << insertPos << std::endl;
}

void	PhoneBook::search(void) const {
	size_t	index;

	for (size_t i = 0; i < PhoneBook::maxContactCount; i++) {
		displayShortContact(i);
	}
	if (getIndexFromUser(&index, this->m_contactCount)) {
		displayFullContact(index - 1);
	}
}

bool	PhoneBook::getIndexFromUser(size_t* index, size_t max) {
	std::string	input;
	int	nb = -1;
	int	attempts = 0;

	while (attempts <= 3)
	{
		std::cout << "Please enter the index of the contact you want to see more: " << std::endl;
		std::cin >> input;
		attempts++;
		if (std::cin.fail()) {
			std::cerr << "Error while getting user input" << std::endl;
			std::cin.clear();
		}
		try {
			nb = std::stoi(input, nullptr);
		}
		catch (std::invalid_argument) {
			std::cout << "Invalid index." << std::endl;
		}
		if (1 <= nb && nb <= (int)max) {
			*index = (size_t)nb;
			return true;
		}
		std::cout << "Enter an index between 1 and " << max << std::endl;
	}
	return false;
}

// size_t	getMaxContactCount(void) { return PhoneBook::maxContactCount; }

void	PhoneBook::displayFullContact(size_t index) const {
	const std::string	hints[] = { "first name: ", "last name: ", "nickname: ", "phone number: ", "secret: " };
	const Cgetter		getters[] = { &Contact::getFirstName, &Contact::getLastName, &Contact::getNickname, &Contact::getPhoneNumber, &Contact::getSecret };
	const size_t		hintCount = 5;

	for (size_t i = 0; i < hintCount; i++) {
		std::cout << hints[i] << (this->m_contacts[index].*getters[i])() << std::endl;
	}
}

void	PhoneBook::displayShortContact(size_t index) const {
	const Cgetter	getters[] = { &Contact::getFirstName, &Contact::getLastName, &Contact::getNickname };
	const size_t	count = 3;

	configureOutput();
	std::cout << index + 1 << '|';
	for (size_t i = 0; i < count; i++) {
		configureOutput();
		std::cout << truncate((this->m_contacts[index].*getters[i])(), 10);
		if (i == count - 1)
			std::cout << std::endl;
		else
			std::cout << '|';
	}
}

void	PhoneBook::configureOutput(void) {
	std::cout << std::setw(10) << std::right;
}

std::string	PhoneBook::truncate(std::string s, size_t len) {
	if (s.length() <= len) {
		return s;
	}
	return s.replace(len - 1, std::string::npos, ".");
}
