#ifndef CONTACT
#define CONTACT

#include <string>

class Contact {

public:

	Contact(void);
	Contact(
		std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string secret);
	~Contact(void);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getSecret(void) const;

	bool		setFirstName(std::string firstName);
	bool		setLastName(std::string lastName);
	bool		setNickname(std::string nickname);
	bool		setPhoneNumber(std::string phoneNumber);
	bool		setSecret(std::string secret);

	static bool	isValidPhoneNunmber(std::string phoneNumber);

private:

	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickname;
	std::string	m_phoneNumber;
	std::string	m_secret;

};

#endif
