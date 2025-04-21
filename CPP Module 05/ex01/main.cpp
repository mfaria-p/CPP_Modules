#include "Bureaucrat.hpp"

// When an exception is thrown, the destructor of the object is called as 
// part of the stack unwinding process before the exception is caught by the catch block.

int main()
{
    std::cout << "\n********** Creating a form out of bounds **********\n" << std::endl;
    try
    {
        Form f0("Form0", 0, 0); // This should throw GradeTooHighException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n********** Creating a Bureaucrat with a grade lower than the necessary to sign the form **********\n" << std::endl;
    try
    {
        Bureaucrat b1("Charlie", 75);
        Form f1("Form1", 50, 50);
        std::cout << f1 << std::endl;
        b1.signForm(f1); // This should throw GradeTooLowException
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\n********** Creating a Bureaucrat with a grade equal to the necessary to sign the form **********\n" << std::endl;
    try
    {
        Bureaucrat b2("Dave", 50);
        Form f2("Form2", 50, 70);
        std::cout << f2 << std::endl;
        b2.signForm(f2); // This should succeed
        std::cout << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\n********** Creating a Bureaucrat with a grade higher than the necessary to sign the form **********\n" << std::endl;
    try
    {
        Bureaucrat b3("Gertrudes", 30);
        Form f3("Form3", 50, 25);
        std::cout << f3 << std::endl;
        b3.signForm(f3); // This should succeed
        std::cout << std::endl;
        std::cout << f3 << std::endl;
        std::cout << "********** Trying to sign the same form twice**********\n" << std::endl;
        b3.signForm(f3); // its already signed
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}