#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "A default Bureaucrat has been constructed" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "A Bureaucrat constructor has been called!" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        _grade = grade;
        std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has been constructed" << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat._name + "_copy"), _grade(bureaucrat._grade) 
{
    std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has been constructed from a copy" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
    if (this != &bureaucrat)
        _grade = bureaucrat._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has been destroyed" << std::endl;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
    std::cout << "Incrementing bureaucrat " << _name << "'s grade " << _grade << " by 1" << std::endl;
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    std::cout << "Decrementing bureaucrat " << _name << "'s grade " << _grade << " by 1" << std::endl;
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

// The const keyword ensures that calling the function on a object will 
//not modify the state of the object. This is important for functions 
//that are meant to provide information without altering the object, 
//such as error message functions.
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

// The << operator is overloaded to print the object in the desired format.
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(Form &form)
{
    if (form.getSigned())
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because the form is already signed" << std::endl;
    }
    else
    {
        try
        {
            form.beSigned(*this);
            std::cout << _name << " signed " << form.getName() << std::endl;
        }
        // here it catches the exception thrown by the beSigned function
        catch (std::exception &e)
        {
            std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
        }
    }
}