#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : m_contactCount(0) {
	std::cout << "Default PhoneBook Constuctor called" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destuctor called" << std::endl;
}

void	PhoneBook::add(void) {
	const std::string	hints[] = {
							"first name: ",
							"last name: ",
							"nickname: ",
							"phone number: ",
							"secret: " };
	const Csetter		setters[] = {
							&Contact::setFirstName,
							&Contact::setLastName,
							&Contact::setNickname,
							&Contact::setPhoneNumber,
							&Contact::setSecret };
	const size_t		hintCount = 5;

	Contact				contactToAdd;
	std::string			input;
	bool				success = false;
	size_t				failed_attempts = 0;
	size_t				i = 0;

	std::cout << "ADD Contact. Please provide info about the contact"
		<< std::endl;
	while (i < hintCount && failed_attempts < 3)
	{
		std::cout << hints[i];
		if (!std::getline(std::cin, input)) {
			input.clear();
		}
		success = (contactToAdd.*setters[i])(input);
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
	this->add(contactToAdd);
}

void	PhoneBook::add(const Contact& c) {
	const size_t	insertPos
		= this->m_contactCount % PhoneBook::maxContactCount;
	const Csetter	setters[] = {
						&Contact::setFirstName,
						&Contact::setLastName,
						&Contact::setNickname,
						&Contact::setPhoneNumber,
						&Contact::setSecret };
	const Cgetter	getters[] = {
						&Contact::getFirstName,
						&Contact::getLastName,
						&Contact::getNickname,
						&Contact::getPhoneNumber,
						&Contact::getSecret };
	const size_t	count = 5;

	for (size_t i = 0; i < count; i++) {
		(this->m_contacts[insertPos].*setters[i])((c.*getters[i])());
	}
	this->m_contactCount++;
	std::cout << "Contact added at index:" << insertPos << std::endl;
}

void	PhoneBook::search(void) const {
	size_t	index;
	size_t	max;

	if (m_contactCount == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	displayHeader();
	for (size_t i = 0; i < PhoneBook::maxContactCount; i++) {
		displayShortContact(i);
	}
	if (this->m_contactCount <= PhoneBook::maxContactCount) {
		max = this->m_contactCount;
	}
	else {
		max = PhoneBook::maxContactCount;
	}
	if (getIndexFromUser(&index, max)) {
		displayFullContact(index);
	}
}

bool	PhoneBook::getIndexFromUser(size_t* index, size_t max) const {
	std::string	input;
	int			nb = -1;
	int			attempts = 0;

	while (attempts < 3)
	{
		std::cout
			<< "Please enter the index of the contact you want to see more: "
			<< std::endl;
		if (!std::getline(std::cin, input)) {
			input.clear();
		}
		attempts++;
		try {
			nb = std::stoi(input, nullptr);
		}
		catch (std::invalid_argument) {
			std::cerr << "Invalid index." << std::endl;
			continue;
		}
		if (1 <= nb && nb <= (int)max) {
			*index = (size_t)nb;
			return true;
		}
		std::cerr << "index must be between 0 and " << max << std::endl;
	}
	std::cerr << "To many failed attempts" << std::endl;
	return false;
}

void	PhoneBook::displayFullContact(size_t index) const {
	const std::string	hints[] = {
							"first name: ",
							"last name: ",
							"nickname: ",
							"phone number: ",
							"secret: " };
	const Cgetter		getters[] = {
							&Contact::getFirstName,
							&Contact::getLastName,
							&Contact::getNickname,
							&Contact::getPhoneNumber,
							&Contact::getSecret };
	const size_t		hintCount = 5;

	for (size_t i = 0; i < hintCount; i++) {
		std::cout << hints[i] << (this->m_contacts[index].*getters[i])()
		<< std::endl;
	}
}

void	PhoneBook::displayShortContact(size_t index) const {
	const Cgetter	getters[] = {
						&Contact::getFirstName,
						&Contact::getLastName,
						&Contact::getNickname };
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

void	PhoneBook::displayHeader(void) const {
	const std::string	titles[] = {
							"Index",
							"First Name",
							"Last Name",
							"Nickname" };
	const size_t		titleCount = 4;

	for (size_t i = 0; i < titleCount; i++)
	{
		configureOutput();
		std::cout << titles[i];
		if (i == titleCount - 1)
			std::cout << std::endl;
		else
			std::cout << '|';
	}
}

void	PhoneBook::configureOutput(void) const {
	std::cout << std::setw(10) << std::right;
}

std::string	PhoneBook::truncate(std::string s, size_t len) const {
	if (s.length() <= len) {
		return s;
	}
	return s.replace(len - 1, std::string::npos, ".");
}
