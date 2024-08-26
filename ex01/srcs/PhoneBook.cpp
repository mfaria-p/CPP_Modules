#include "../includes/header.hpp"

PhoneBook::PhoneBook () { //to inicialize the whole phonebook
    n_contacts = 0;
}

void PhoneBook::add_to_book(int index) {
    index = n_contacts % 8;
    contacts[index].set_contact();
    n_contacts++;
}

void PhoneBook::print_data(void) {
    int index = 0;
    std::string line;

    if (n_contacts > 0)
    {
        std::cout << "     Index|    F_name|    L_name|  Nickname" << std::endl;
        while(index < n_contacts && index < 8)
		{
			contacts[index].print_table(index);
			index++;
		}
        while (1)
        {
            std::cout << "Type Contact Index for more information: ";
            std::getline(std::cin, line);
            if (std::cin.eof()) {
                std::cout << std::endl << "User interrupted the program. Exiting..." << std::endl;
                exit(EXIT_SUCCESS);
            }
            index = atoi(line.c_str());
            index -= 1;
            if (index >= 0 && index < n_contacts && index < 8)
            {
				contacts[index].print_contact();
				break ;
			}
            else
                std::cout << "Contact index not found." << std::endl;
        }
    }
    else
        std::cout << "No Contacts added yet" << std::endl;
}