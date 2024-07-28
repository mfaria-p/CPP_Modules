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
        std::cout << "enter a command: ";
        std::getline (std::cin,cmd);
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
