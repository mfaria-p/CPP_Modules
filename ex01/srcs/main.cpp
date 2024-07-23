#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

#include <iostream>

int main(void)
{
    std::string cmd;
    PhoneBook Phone;
    int index;

    index = 0;
    std::cout << "The most incredible PhoneBoom you will ever see" << std::endl;
    while (1)
    {
        std::cout << "enter a command: ";
        std::cin >> cmd;
        if (cmd == "ADD")
        {
            while (Phone.isContactUsed(index)) {
				if (index ==  7) {
					index = 0;
					break;
				}
				index++;
			}
            Phone.add_to_book(index);
        }
    }

}
