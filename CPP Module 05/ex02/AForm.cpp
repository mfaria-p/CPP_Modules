#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) 
{
    std :: cout << "Form default constructor called" << std :: endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std :: cout << "Form constructor called" << std :: endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std :: cout << "Form copy constructor called" << std :: endl;
}

AForm::~AForm()
{
    std :: cout << "Form destructor called" << std :: endl;
}

AForm &AForm::operator=(AForm const &form)
{
    std :: cout << "Form assignment operator called" << std :: endl;
    if (this != &form)
    {
        _signed = form._signed;
    }
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed, so it cannot be executed";
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Form signed: " << form.getSigned() << std::endl;
    out << "Form grade to sign: " << form.getGradeToSign() << std::endl;
    out << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}

void AForm::execute(Bureaucrat const & executor) const 
{
    (void)executor;
}

