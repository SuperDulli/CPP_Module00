#ifndef CONTACT
#define CONTACT

#include <string.h>

class Contact {

public:

	Contact(void);
	Contact(const Contact& c);
	Contact(
		std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string secret)
	~Contact(void);
	Contact&	operator=(const Contact& c);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getSecret(void) const;

private:

	std::string	firstName;
	std::string	lastName;
	std::string	nickame;
	std::string	phoneNumber;
	std::string	secret;

};

#endif
