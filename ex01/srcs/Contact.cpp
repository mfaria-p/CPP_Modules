#include "../includes/header.hpp"

int Contact::contact_exist() {
    if (initialized == true)
        return(1);
}

void Contact::set_contact () {
    std::system("clear");
	std::cout << "First Name: ";
	//std::cin.ignore();
	while (first_name.empty()) {
				std::getline(std::cin, first_name);
				if (first_name.empty()) {
					std::cout << "You can't have an empty first name. Try again..." << std::endl;
					std::cout << "First Name: ";
				}
			}
    std::cout << "\nLast Name: ";
	while (last_name.empty()) {
		std::getline(std::cin, last_name);
		if (last_name.empty()) {
			std::cout << "You can't have an empty last name. Try again...\n";
			std::cout << "Last Name: ";
		}
	}
    std::cout << "\nNickname: ";
	while (nickname.empty()) {
		std::getline(std::cin, nickname);
		if (nickname.empty()) {
			std::cout << "You can't have an empty nickname. Try again...\n";
			std::cout << "Nickname: ";
		}
	}
    std::cout << "\nPhone Number: ";
	while (phone_number.empty()) {
		std::getline(std::cin, phone_number);
		if (phone_number.empty()) {
			std::cout << "You can't have an empty phone number. Try again...\n";
			std::cout << "Phone Number: ";
	    }
	}
    std::cout << "\nDarkest Secret: ";
			while (darkest_secret.empty()) {
				std::getline(std::cin, darkest_secret);
				if (darkest_secret.empty()) {
					std::cout << "You can't have an empty darkest secret. Try again...\n";
					std::cout << "Please input your darkest secret: ";
				}
			}
    initialized = true;
}