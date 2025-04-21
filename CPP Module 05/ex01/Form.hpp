#ifndef EX01_FORM_HPP
# define EX01_FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;

    public:
        Form(); // default constructor
        Form(std::string name, int gradeToSign, int gradeToExecute); // grade 1-150
        Form(Form const &src); // copy constructor
        ~Form(); // destructor
        Form &operator=(Form const &form); // assignment operator

        // getters
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // member functions
        void beSigned(Bureaucrat &bureaucrat);

        // Exception classes
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif