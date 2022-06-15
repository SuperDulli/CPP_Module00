#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void) {
	std::string	input;
	PhoneBook	myAwesomePhoneBook;

	while (1) {
		std::cout << "Specify want you want to do: [ADD] [SEARCH] [EXIT]"
		<< std::endl;
		if (!std::getline(std::cin, input)) {
			std::cerr << "Expected cmd found EOF instead" << std::endl;
			break ; 
		}
		if (!input.compare("ADD")) {
			myAwesomePhoneBook.add();
		} else if (!input.compare("SEARCH")) {
			myAwesomePhoneBook.search();
		} else if (!input.compare("EXIT")) {
			break ;
		} else {
			std::cout << input << " :Command not supported" << std::endl;
		}
	}
	return 0;
}
