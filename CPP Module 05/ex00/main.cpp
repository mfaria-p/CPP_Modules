#include "Bureaucrat.hpp"

// When an exception is thrown, the destructor of the object is called as 
// part of the stack unwinding process before the exception is caught by the catch block.
int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade(); // This should throw GradeTooHighException
        std::cout << b1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b5("Joana", 2);
        std::cout << b5 << std::endl;
        b5.incrementGrade(); // This should work
        std::cout << b5 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade(); // This should throw GradeTooLowException
        std::cout << b2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b6("Meh", 149);
        std::cout << b6 << std::endl;
        b6.decrementGrade(); // This should work
        std::cout << b6 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b3("Charlie", 0); // This should throw GradeTooHighException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b4("Dave", 151); // This should throw GradeTooLowException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}