#ifndef EX03_PRESIDENTIAL_HPP
#define EX03_PRESIDENTIAL_HPP

#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &form);

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

    private:
        std::string _target;
};

#endif