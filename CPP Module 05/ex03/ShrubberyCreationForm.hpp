#ifndef EX03_SHRUBBERY_HPP
# define EX03_SHRUBBERY_HPP
#include "Form.hpp"
#include <fstream>

class Form;

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

        class FileNotOpenedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FileNotClosedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:
        std::string _target;
};

#endif