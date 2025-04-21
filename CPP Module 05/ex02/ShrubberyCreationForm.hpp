#ifndef SHRUBBERY
# define SHRUBBERY
#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
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