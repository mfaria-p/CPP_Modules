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
	while (std::getline(std::cin, first_name))
    {
        if (!ft_isalpha(first_name) || first_name.empty())
        {
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "First Name: ";
            continue;
        }
		break ;
	}
	std::cout << "Last Name: ";
    while (std::getline(std::cin, last_name))
    {
        if (!ft_isalpha(last_name) || last_name.empty())
        {
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Last Name: ";
            continue;
        }
		break ;
	}
	std::cout << "Nickname: ";
    while (std::getline(std::cin, nickname))
    {
        if (!ft_isalpha(nickname) || nickname.empty())
        {
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Nickname: ";
            continue;
        }
		break ;
	}
	std::cout << "Phone Number: ";
    while (std::getline(std::cin, phone_number))
    {
        if (!ft_isdigit(phone_number) || phone_number.empty())
        {
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Phone Number: ";
            continue;
        }
		break ;
	}
    std::cout << "Darkest Secret: ";
    while (std::getline(std::cin, darkest_secret))
    {
        if (darkest_secret.empty())
        {
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Darkest Secret: ";
            continue;
        }
		break ;
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