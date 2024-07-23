#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    Contact contacts[8];
    int n_contacts;
    public:
        PhoneBook () { //to inicialize the whole phonebook
            n_contacts = 0;
        }
        void isContactUsed(int index);
        void add_to_book(int index);
        void print_all_contacts();
        void search_contact();
};
#endif