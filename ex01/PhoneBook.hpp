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
	
	static const size_t	maxContactCount = 8;
	Contact				contacts[maxContactCount];
	size_t				contactCount;

	void	displayShortContact(size_t index);
	void	displayFullContact(size_t index);

	// Contact&	getContact(size_t i);

};

#endif
