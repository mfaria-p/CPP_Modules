#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        bool initialized;
    public:
        void set_contact ();
        int contact_exist();
    };

#endif