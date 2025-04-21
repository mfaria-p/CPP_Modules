#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm_def", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src), _target(src._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &form)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &form)
    {
        _target = form._target;
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

//to ensure that you get a different sequence of random numbers each time you run 
//your program, you need to seed the random number generator using srand() with a 
// seed value, typically the current time. This will ensure that rand() produces a 
//different sequence of random numbers each time you run your program.
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();
    std::cout << "*drilling noises*" << std::endl;
    int success = rand() % 2;
    if (success == 1)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization has failed" << std::endl;  
}
