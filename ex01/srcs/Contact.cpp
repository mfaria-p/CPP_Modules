#include "../includes/header.hpp"

int Contact::contact_exist() {
    if (initialized == true)
        return(1);
	else
		return(0);
}

void Contact::set_contact () {
	std::cout << "First Name: ";
	while (first_name.empty()) {
				std::getline(std::cin, first_name);
				if (first_name.empty()) {
					std::cout << "You can't have an empty first name. Try again..." << std::endl;
					std::cout << "First Name: ";
				}
			}
    std::cout << "Last Name: ";
	while (last_name.empty()) {
		std::getline(std::cin, last_name);
		if (last_name.empty()) {
			std::cout << "You can't have an empty last name. Try again...\n";
			std::cout << "Last Name: ";
		}
	}
    std::cout << "Nickname: ";
	while (nickname.empty()) {
		std::getline(std::cin, nickname);
		if (nickname.empty()) {
			std::cout << "You can't have an empty nickname. Try again...\n";
			std::cout << "Nickname: ";
		}
	}
    std::cout << "Phone Number: ";
	while (phone_number.empty()) {
		std::getline(std::cin, phone_number);
		if (phone_number.empty()) {
			std::cout << "You can't have an empty phone number. Try again...\n";
			std::cout << "Phone Number: ";
	    }
	}
    std::cout << "Darkest Secret: ";
			while (darkest_secret.empty()) {
				std::getline(std::cin, darkest_secret);
				if (darkest_secret.empty()) {
					std::cout << "You can't have an empty darkest secret. Try again...\n";
					std::cout << "Please input your darkest secret: ";
				}
			}
    initialized = true;
};

void truncate_print(const std::string& str) {
	if (str.length() > 10)
		std::cout << str.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void Contact::print_table(int index) {
	std::cout << std::setw(10) << index + 1;
	std::cout << "|";
	truncate_print(first_name);
	std::cout << "|";
	truncate_print(last_name);
	std::cout << "|";
	truncate_print(nickname);
	std::cout << std::endl;
};

void Contact::print_contact(void) {
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}