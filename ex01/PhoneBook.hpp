#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void) const;

	// static size_t		getMaxContactCount(void);
	
private:
	
	static const size_t	maxContactCount = 8;
	Contact				m_contacts[maxContactCount];
	size_t				m_contactCount;

	void				displayShortContact(size_t index) const;
	void				displayFullContact(size_t index) const;

	static void			configureOutput(void);
	static std::string	truncate(std::string s, size_t len);
	static bool			getIndexFromUser(size_t* index, size_t max);
};

#endif
