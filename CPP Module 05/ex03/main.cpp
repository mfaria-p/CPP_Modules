#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(0)); // Seed the random number generator

    Intern someRandomIntern;
    Bureaucrat b1("Alice", 1);
    Form* rrf;
    Form* scf;
    Form* ppf;
    Form* form;

    std::cout << "\n********** Testing Intern Robotomy Request Form Creation **********\n" << std::endl;
    try
    {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << std::endl;
        std::cout << *rrf << std::endl;

        std::cout << "********** Signing and Executing RobotomyRequestForm like before **********\n" << std::endl;
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\n********** Testing Intern Shrubbery Creation Form Creation **********\n" << std::endl;

    try
    {
        scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        std::cout << std::endl;
        std::cout << *scf << std::endl;

        std::cout << "********** Signing and Executing ShrubberyCreationForm like before **********\n" << std::endl;
        b1.signForm(*scf);
        b1.executeForm(*scf);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\n********** Testing Intern Presidential Pardon Form Creation **********\n" << std::endl;

    try
    {
        ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
        std::cout << std::endl;
        std::cout << *ppf << std::endl;
        std::cout << "********** Signing and Executing PresidentialPardonForm like before **********\n" << std::endl;
        b1.signForm(*ppf);
        b1.executeForm(*ppf);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\n********** Testing Intern Unknown Form Creation **********\n" << std::endl;
    try
    {
        form = someRandomIntern.makeForm("unknown form", "Unknown");
        b1.signForm(*form);
        b1.executeForm(*form);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    delete rrf;
    delete scf;
    delete ppf;
    return 0;
}

/* int	main(void)
{
	std::srand(std::time(0)); // common practice to seed the pseudo-random number generator

	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Intern	intern;
	Form	*robo_form;
	Form	*shrub_form;
	Form	*president_form;
	Form	*unknown_form;
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "INTERN TESTS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	// Robo:
	robo_form = intern.makeForm("robotomy request", "robo");
	std::cout << *robo_form << " was just created " << std::endl << std::endl;

	// President:
	president_form = intern.makeForm("presidential pardon", "president");
	std::cout << *president_form << " was just created " << std::endl << std::endl;

	// Shrub:
	shrub_form = intern.makeForm("shrubbery creation", "shrub");
	std::cout << *shrub_form << " was just created " << std::endl << std::endl;

	// Unknown:
	try
	{
		unknown_form = intern.makeForm("driving licence", "drive");
		std::cout << *unknown_form << " was just created " << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	delete robo_form;
	delete shrub_form;
	delete president_form;
	delete unknown_form;
	return (0);
	//-------------------------------------------------------	
} */