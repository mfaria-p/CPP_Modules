#include "../includes/header.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook Phone;
    int index;

    index = 0;
    std::cout << "The most incredible PhoneBook you will ever see :)" << std::endl;
    while (1)
    {
        std::cout << "enter a command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, cmd);
        if (std::cin.eof()) {
            std::cout << std::endl << "User interrupted the program. Exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        }
        if (cmd == "ADD")
            Phone.add_to_book(index);
        else if (cmd == "SEARCH")
        {
            Phone.print_data();
        }
        else if (cmd == "EXIT")
        {
            std::cout << "Exiting from the awesome PhoneBook :)\n";
            exit(EXIT_SUCCESS);
        }
        else
            std::cout << "Comand not Found... Try again\n";
    }

}
