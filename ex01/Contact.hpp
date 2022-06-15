#ifndef CONTACT
#define CONTACT

#include <string>


class Contact {

public:

	Contact(void);
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

typedef bool (Contact::* Csetter)(std::string);
typedef std::string(Contact::* Cgetter)(void) const;

#endif

