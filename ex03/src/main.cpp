/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:25 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/14 15:25:02 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"
#include "../include/Colors.hpp"


static void waitForEnter()
{
	std::cout << DARK_GREY "Press " << BOLD "Enter" << DARK_GREY " to move to next test... ";
	
	std::cin.get();  // Waits for the user to press Enter
}

using RunTest = void (*)();

static void handleExceptions(RunTest testCase)
{
	try
	{
		testCase();
	}
	catch(const std::exception &e)
	{
		std::cerr << "❗ Exception found: " << e.what() << std::endl;
	}
}

static void testInternCreatesForms()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"  TEST  : Intern Form Creation Test         " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;

	Intern bob;
	Bureaucrat exec("Mak", 1);

	std::string names[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; ++i)
	{
		AForm* form = bob.makeForm(names[i], "TestTarget");

		if (form)
		{
			std::cout << "\n🧾 " << *form << std::endl;
			exec.signForm(*form);
			exec.executeForm(*form);
			delete form;
		}
	}

	// Invalid case
	std::cout << "\n⚠️  Creating an unknown form...\n";
	AForm* unknown = bob.makeForm("unknown request", "Nowhere");
	if (!unknown)
		std::cout << "✅ Intern handled unknown form gracefully.\n";
}

int main()
{
	handleExceptions(testInternCreatesForms);
	std::cout << std::endl;
	waitForEnter();
	
	std::cout << "\n✅ End of tests." << std::endl;
	
	return (0);
}
