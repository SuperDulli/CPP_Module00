#include <iostream>
#include <string>

namespace megaphone {
	const std::string	default_msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string			amplify(char* messages[], size_t msg_count);
}

std::string	megaphone::amplify(char* messages[], size_t msg_count) {
	std::string	result = "";
	for (size_t i = 0; i < msg_count; i++) {
		std::string	msg = messages[i];
		for (size_t j = 0; j < msg.length(); j++) {
			msg[j] = std::toupper(msg[j]);
		}
		result += msg;
	}
	return result;
}

int	main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << megaphone::default_msg << std::endl;
		return 1;
	}
	std::cout << megaphone::amplify(&argv[1], argc - 1) << std::endl;
	return 0;
}
