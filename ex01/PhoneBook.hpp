#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void) const;

private:
	
	static const size_t	maxContactCount = 8;
	Contact				m_contacts[maxContactCount];
	size_t				m_contactCount;

	void				add(const Contact& c);

	void				displayShortContact(size_t index) const;
	void				displayFullContact(size_t index) const;
	void				displayHeader(void) const;

	void				configureOutput(void) const ;
	std::string			truncate(std::string s, size_t len) const ;
	bool				getIndexFromUser(size_t* index, size_t max) const;
};

#endif
