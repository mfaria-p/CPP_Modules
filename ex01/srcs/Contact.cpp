#include "../includes/header.hpp"


bool    ft_isalpha(std::string str)
{
    std::string:: iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++) {
        if (!isalpha(*itr))
            return (false);
    }
    return (true);
}

bool    ft_isdigit(std::string str)
{
    std::string:: iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++) {
        if (!isdigit(*itr))
            return (false);
    }
    return (true);
}

void Contact::set_contact () {
    std::cout << "First Name: ";
	while (true) {
        std::getline(std::cin, first_name);
        if (std::cin.eof()) {
            std::cout << std::endl << "User interrupted the program. Exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        }
        if (!ft_isalpha(first_name) || first_name.empty()) {
            std::cout << "Invalid first name. Try again..." << std::endl;
            std::cout << "First Name: ";
        } else break;
    }
    std::cout << "Last Name: ";
    while (true) {
        std::getline(std::cin, last_name);
        if (std::cin.eof()) {
            std::cout << std::endl << "User interrupted the program. Exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        }
        if (!ft_isalpha(last_name) || last_name.empty()) {
            std::cout << "Invalid last name. Try again..." << std::endl;
            std::cout << "Last Name: ";
        } else break;
    }

    std::cout << "Nickname: ";
    while (true) {
        std::getline(std::cin, nickname);
        if (std::cin.eof()) {
            std::cout << std::endl << "User interrupted the program. Exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        }
        if (nickname.empty()) {
            std::cout << "Invalid nickname. Try again..." << std::endl;
            std::cout << "Nickname: ";
        } else break;
    }

    std::cout << "Phone Number: ";
    while (true) {
        std::getline(std::cin, phone_number);
        if (std::cin.eof()) {
            std::cout << std::endl << "User interrupted the program. Exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        }
        if (!ft_isdigit(phone_number) || phone_number.empty()) {
            std::cout << "Invalid phone number. Try again..." << std::endl;
            std::cout << "Phone Number: ";
        } else break;
    }

    std::cout << "Darkest Secret: ";
    while (true) {
        std::getline(std::cin, darkest_secret);
        if (std::cin.eof()) {
            std::cout << std::endl << "User interrupted the program. Exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        }
        if (darkest_secret.empty()) {
            std::cout << "You can't have an empty darkest secret. Try again..." << std::endl;
            std::cout << "Darkest Secret: ";
        } else break;
    }
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