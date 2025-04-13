/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:25 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/13 10:26:19 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
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

static void testShrubberyForm()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"      TEST 7️⃣ : ShrubberyCreationForm execution        " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	
	try
	{
		Bureaucrat mak("Mak", 1);
		ShrubberyCreationForm form("backyard");
		
		std::cout << mak << std::endl;
		std::cout << form << std::endl;
		
		// std::cout << GREEN "\n✅ Signing the form...\n" RESET;
		mak.signForm(form);
		if (form.getIsSigned())
		std::cout << GREEN "✅ Form was signed successfully.\n" RESET;
		else
		std::cout << RED "❌ Form is still unsigned.\n" RESET;
		
		std::cout << GREEN "\n✅ Executing the form...\n" RESET;
		mak.executeForm(form);
		
		std::cout << GREEN "\n🎉 Check the file: backyard_shrubbery\n" RESET;
		
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

static void testRobotomyHeader()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"      TEST 8️⃣ : RobotomyRequestForm header build test      " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	
	try {
		RobotomyRequestForm r("marvin");
		std::cout << "✅ RobotomyRequestForm object constructed successfully!\n";
		std::cout << r << std::endl; // Check << overload works from AForm
	} catch (const std::exception& e) {
		std::cerr << RED "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

static void testRobotomyExecution()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"      TEST 9️⃣ : RobotomyRequestForm Successful execution test      " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	
	try
	{
		Bureaucrat mak("Mak", 1);
		RobotomyRequestForm form("marvin");
		
		std::cout << mak << std::endl;
		std::cout << form << std::endl;
		
		std::cout << GREEN "\n✒️  Signing the form...\n" RESET;
		mak.signForm(form);
		if (form.getIsSigned())
			std::cout << GREEN "✅ Form was signed successfully.\n" RESET;
		else
			std::cout << RED "❌ Form is still unsigned.\n" RESET;
		
		std::cout << GREEN "\n📥 Executing the form...\n" RESET;
		mak.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

static void testRobotomyExecutionFail()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"      TEST 🔟 : RobotomyRequestForm Failed execution test      " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	
	try
	{
		Bureaucrat noob("Intern Mak", 68);
		RobotomyRequestForm form("marvin");
		
		std::cout << noob << std::endl;
		std::cout << form << std::endl;
		
		std::cout << GREEN "\n✒️  Signing the form...\n" RESET;
		noob.signForm(form);
		if (form.getIsSigned())
		std::cout << GREEN "✅ Form was signed successfully.\n" RESET;
		else
		std::cout << RED "❌ Form is still unsigned.\n" RESET;
		
		std::cout << GREEN "\n📥 Intern tries to execute the form...\n" RESET;
		std::cout << YELLOW "⚠️  Expecting execution to FAIL due to low grade...\n" RESET;

		noob.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED "❌ Exception: " << e.what() << RESET << std::endl;
	}
}

int main()
{
	std::srand(std::time(nullptr)); // ? check again Seed the random number generator
	
	handleExceptions(testShrubberyForm);
	std::cout << std::endl;
	waitForEnter();

	handleExceptions(testRobotomyHeader);
	std::cout << std::endl;
	waitForEnter();

	handleExceptions(testRobotomyExecution);
	std::cout << std::endl;
	waitForEnter();

	handleExceptions(testRobotomyExecutionFail);
	std::cout << std::endl;
	waitForEnter();
	
	
	std::cout << "\n✅ End of tests." << std::endl;
	
	return (0);
}
