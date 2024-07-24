#include "../includes/header.hpp"

PhoneBook::PhoneBook () { //to inicialize the whole phonebook
    n_contacts = 0;
}

int PhoneBook::isContactUsed (int index) {
	return (contacts[index].contact_exist());
}

void PhoneBook::add_to_book(int index) {
    contacts[index].set_contact();
}