#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "A default Intern has been constructed" << std::endl;
}

Intern::Intern(Intern const &ref)
{
    std::cout << "An Intern has been constructed from a copy" << std::endl;
    *this = ref;
}

Intern &Intern::operator=(Intern const &ref)
{
    std::cout << "Intern " << this << " has been assigned to Intern " << &ref << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "An Intern has been destroyed" << std::endl;
}

static Form* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static Form* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static Form* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
    struct FormType {
        std::string name;
        Form* (*create)(const std::string&);
    };

    static FormType formTypes[] = {
        {"shrubbery creation", &createShrubberyCreationForm},
        {"robotomy request", &createRobotomyRequestForm},
        {"presidential pardon", &createPresidentialPardonForm}
    };

    for (int i = 0; i < 3; ++i) {
        if (formTypes[i].name == form_name) {
            std::cout << "Intern creates " << form_name << std::endl;
            return formTypes[i].create(form_target);
        }
    }
    throw Intern::NoFormException();
}

const char *Intern::NoFormException::what() const throw()
{
    return "Intern cannot create this form";
}