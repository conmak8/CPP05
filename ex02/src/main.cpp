/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:25 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/13 00:52:35 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
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

// static void test1()
// {
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	std::cout << CYAN BOLD"         TEST 1️⃣ : Bureaucrat & AForm creation           " RESET << std::endl;
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	// Bureaucrat a;
// 	Bureaucrat mk("Mak", 42);
// 	AForm F("AForm", 42, 42);

// 	std::cout << std::endl << mk << F << std::endl;
// }

// static void test2()
// {
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	std::cout << CYAN BOLD"         TEST 2️⃣ : Invalid forms Grades           " RESET << std::endl;
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	try
// 	{
// 		AForm f1("Form1", 100, 150);
// 		std::cout << f1 << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "❌ Form1 error: " << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		AForm f2("Form2", 0, 150); // too high
// 		std::cout << f2;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "❌ Form2 error: " << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		AForm f3("Form3", 100, 151); // too low
// 		std::cout << f3;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "❌ Form3 error: " << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		AForm f4("Form3", 0, 151); // too low & too high
// 		std::cout << f4;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "❌ Form4 error: " << e.what() << std::endl;
// 	}
// }

// static void test3()
// {
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	std::cout << CYAN BOLD"         TEST 3️⃣ : Bureaucrat can sign the AForm           " RESET << std::endl;
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	Bureaucrat mk("Mak", 42);
// 	AForm f("Report", 100, 150);

// 	std::cout << mk << std::endl;
// 	std::cout << f << std::endl;

// 	mk.signForm(f);
// 	std::cout << f << std::endl;

// }

// static void test4()
// {
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	std::cout << CYAN BOLD"         TEST 4️⃣ : Bureaucrat can NOT sign the AForm           " RESET << std::endl;
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	Bureaucrat mk("Mak", 108);
// 	AForm f("Report", 100, 150);

// 	std::cout << mk << std::endl;
// 	std::cout << f << std::endl;

// 	mk.signForm(f);
// 	std::cout << f << std::endl;

// }

// static void test5()
// {
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	std::cout << CYAN BOLD"         TEST 5️⃣ : AForm already signed           " RESET << std::endl;
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	
// 	Bureaucrat mk("Mak", 42);
// 	AForm f("Report", 100, 150);

// 	std::cout << std::endl << mk << std::endl;
// 	mk.signForm(f);
// 	std::cout << f;

// 	if (f.getIsSigned())
// 		std::cout << "✅ AForm was signed successfully.\n";
// 	else
// 		std::cout << "❌ AForm is still unsigned.\n";
		
// 	// New bureaucrat to try sign the same form:
// 	Bureaucrat b("Dima", 1);
// 	std::cout << std::endl << b << std::endl;
	
// 	b.signForm(f);
	
// 	std::cout << std::endl << f << std::endl;
// }

// static void test6()
// {
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;
// 	std::cout << CYAN BOLD"         TEST 6️⃣ : Invalid Bureaucrat creation           " RESET << std::endl;
// 	std::cout << CYAN"------------------------------------------------------------" << std::endl;

// 	try
// 	{
// 		Bureaucrat ultra("Ultra", 0);
// 		std::cout << ultra << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "❌ Bureaucrat error: " << e.what() << std::endl;
// 	}
// }

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
		// mak.signForm(form);
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

int main()
{
	// handleExceptions(test1);
	// std::cout << std::endl;
	// waitForEnter();
	
	// handleExceptions(test2);
	// std::cout << std::endl;
	// waitForEnter();
	
	// handleExceptions(test3);
	// std::cout << std::endl;
	// waitForEnter();
	
	// handleExceptions(test4);
	// std::cout << std::endl;
	// waitForEnter();
	
	// handleExceptions(test5);
	// std::cout << std::endl;
	// waitForEnter();

	// handleExceptions(test6);
	// std::cout << std::endl;

	handleExceptions(testShrubberyForm);
	std::cout << std::endl;
	waitForEnter();
	
	std::cout << "\n✅ End of tests." << std::endl;
	
	return (0);
}
