#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	PhoneBook(const PhoneBook& pB);
	~PhoneBook(void);
	PhoneBook& operator=(const PhoneBook& pB);

	void	add(const Contact& c);
	void	search(void) const;

private:
	
	Contact	contacts[8];

	void	displayShortContact(size_t index);
	void	displayFullContact(size_t index);

};

#endif
