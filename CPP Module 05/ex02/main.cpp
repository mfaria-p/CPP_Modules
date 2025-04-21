#include "Bureaucrat.hpp"

// When an exception is thrown, the destructor of the object is called as 
// part of the stack unwinding process before the exception is caught by the catch block.

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(0));

    std::cout << "\n********** Testing Bureaucrat and Forms **********\n" << std::endl;

    try
    {
        Bureaucrat b1("Alice", 1);
        ShrubberyCreationForm scf("home");
        RobotomyRequestForm rrf("robot");
        PresidentialPardonForm ppf("Bob");

        std::cout << b1 << std::endl;

        std::cout << "\n********** Signing and Executing ShrubberyCreationForm **********\n" << std::endl;
        b1.signForm(scf);
        b1.executeForm(scf);

        std::cout << "\n********** Signing and Executing RobotomyRequestForm **********\n" << std::endl;
        b1.signForm(rrf);
        b1.executeForm(rrf);

        std::cout << "\n********** Signing and Executing PresidentialPardonForm **********\n" << std::endl;
        b1.signForm(ppf);
        b1.executeForm(ppf);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n********** Testing Bureaucrat with Low Grade **********\n" << std::endl;

    try
    {
        Bureaucrat b2("Charlie", 150);
        ShrubberyCreationForm scf("garden");

        std::cout << b2 << std::endl;

        std::cout << "\n********** Trying to Sign ShrubberyCreationForm with Low Grade **********\n" << std::endl;
        b2.signForm(scf); // This should throw GradeTooLowException
        b2.executeForm(scf); // This should not be executed
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n********** Testing Form Not Signed Exception **********\n" << std::endl;

    try
    {
        Bureaucrat b3("Dave", 50);
        RobotomyRequestForm rrf("robot");

        std::cout << b3 << std::endl;

        b3.executeForm(rrf); // This should throw FormNotSignedException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n********** Testing RobotomyRequestForm Probabilities **********\n" << std::endl;

    try
    {
        Bureaucrat b4("Eve", 1);
        RobotomyRequestForm rrf("robot");
        std::cout << std::endl;

        std::cout << b4 << std::endl;

        b4.signForm(rrf);
        std::cout << std::endl;

        for (int i = 0; i < 10; ++i)
        {
            std::cout << "Attempt " << i + 1 << ": ";
            b4.executeForm(rrf);
            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n********** Testing Grade Too High and Too Low Exceptions **********\n" << std::endl;

    try
    {
        Bureaucrat b5("Frank", 0); // This should throw GradeTooHighException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b6("Grace", 151); // This should throw GradeTooLowException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}