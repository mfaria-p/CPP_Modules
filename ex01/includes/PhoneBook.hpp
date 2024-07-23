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
        void add_contact();
        void print_all_contacts();
        void search_contact();
};
#endif