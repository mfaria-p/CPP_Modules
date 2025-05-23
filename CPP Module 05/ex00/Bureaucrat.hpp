#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;

public:
    Bureaucrat(); // default constructor
    Bureaucrat(std::string name, int grade); // grade 1-150
    Bureaucrat(Bureaucrat const &bureaucrat); // copy constructor
    Bureaucrat &operator=(Bureaucrat const &bureaucrat); // assignment operator
    ~Bureaucrat(); // destructor

    // getters
    std::string getName() const;
    int getGrade() const;

    // Increment and decrement grade
    void incrementGrade();
    void decrementGrade();

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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif