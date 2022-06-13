#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void) {

	Contact a;
	std::cout << a.getFirstName() << std::endl;
	Contact	c = Contact("Chris", "Helmer", "chelmerd", "+123", "none");
	std::cout << c.getFirstName() << std::endl;
	Contact d = c;
	std::cout << d.getFirstName() << std::endl;

	PhoneBook pB;
	pB.add(c);
	PhoneBook pA = pB;
	return 0;
}
