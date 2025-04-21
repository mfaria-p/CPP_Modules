#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) 
{
    std :: cout << "Form default constructor called" << std :: endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std :: cout << "Form constructor called" << std :: endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std :: cout << "Form copy constructor called" << std :: endl;
}

Form::~Form()
{
    std :: cout << "Form destructor called" << std :: endl;
}

Form &Form::operator=(Form const &form)
{
    std :: cout << "Form assignment operator called" << std :: endl;
    if (this != &form)
    {
        _signed = form._signed;
    }
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Form signed: " << form.getSigned() << std::endl;
    out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
    out << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}

