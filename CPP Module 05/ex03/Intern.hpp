#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
		// Canonic class methods:
		Intern();
		~Intern();
		Intern(Intern const & ref);
		Intern & operator=(Intern const & ref);

		// Subject required method:
		Form *makeForm(std::string form_name, std::string form_target);

		// Exception:
		class NoFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


#endif