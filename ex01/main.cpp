#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

namespace phone_book_test {
	void	createContacts(void);
	void	createPhoneBooks(void);
}

int	main(void) {

	// phone_book_test::createContacts();
	phone_book_test::createPhoneBooks();

	return 0;
}

void	phone_book_test::createContacts(void) {
	std::cout << "Creating Contacts (Test)" << std::endl;

	Contact	a;
	Contact	c = Contact("Chris", "Helmer", "chelmerd", "+123", "none");
	Contact d = c;
	Contact	invalid = Contact("Bob", "Andrews", "third", "-1", "has red hair");

	std::cout << c.getFirstName() << std::endl;
	std::cout << c.getLastName() << std::endl;
	std::cout << c.getNickname() << std::endl;
	std::cout << c.getPhoneNumber() << std::endl;
	std::cout << c.getSecret() << std::endl;

	std::cout << "Creating Contacts (Test-End)" << std::endl;
}

void	phone_book_test::createPhoneBooks(void) {
	std::cout << "Creating PhoneBooks (Test)" << std::endl;

	PhoneBook a;
	// PhoneBook pB = PhoneBook();
	a.add();
	a.search();
	// PhoneBook b = a;
	std::cout << "Creating PhoneBooks (Test-End)" << std::endl;
}
