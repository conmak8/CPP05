/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:25 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/07 17:01:53 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"

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

static void test1()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"         TEST 1️⃣ : Bureaucrat & Form creation           " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	// Bureaucrat a;
	Bureaucrat mk("Mak", 42);
	Form F("Form", 42, 42);

	std::cout << mk << F << std::endl;
}

static void test2()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"         TEST 2️⃣ : Bureaucrat & Form creation           " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	try
	{
		Form f1("Form1", 100, 150);
		std::cout << f1;
	}
	catch (const std::exception& e)
	{
		std::cerr << "❌ Form1 error: " << e.what() << std::endl;
	}

	try
	{
		Form f2("Form2", 0, 150); // too high
		std::cout << f2;
	}
	catch (const std::exception& e)
	{
		std::cerr << "❌ Form2 error: " << e.what() << std::endl;
	}

	try
	{
		Form f3("Form3", 100, 151); // too low
		std::cout << f3;
	}
	catch (const std::exception& e)
	{
		std::cerr << "❌ Form3 error: " << e.what() << std::endl;
	}

	try
	{
		Form f4("Form3", 0, 151); // too low & too high
		std::cout << f4;
	}
	catch (const std::exception& e)
	{
		std::cerr << "❌ Form4 error: " << e.what() << std::endl;
	}
}
	
static void test3()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"         TEST 3️⃣ : Bureaucrat can sign the Form           " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	Bureaucrat mk("Mak", 42);
	Form f("Report", 100, 150);

	std::cout << mk << std::endl;
	std::cout << f << std::endl;

	mk.signForm(f);
	std::cout << f << std::endl;

}

static void test4()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"         TEST 4️⃣ : Bureaucrat can NOT sign the Form           " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	Bureaucrat mk("Mak", 108);
	Form f("Report", 100, 150);

	std::cout << mk << std::endl;
	std::cout << f << std::endl;

	mk.signForm(f);
	std::cout << f << std::endl;

}

static void test5()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"         TEST 5️⃣ : Form already signed           " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	
	Bureaucrat mk("Mak", 42);
	Form f("Report", 100, 150);

	std::cout << std::endl << mk << std::endl;
	mk.signForm(f);
	std::cout << f;

	// New bureaucrat to try sign the same form:
	Bureaucrat b("Dima", 1);
	std::cout << std::endl << b << std::endl;
	
	b.signForm(f);
	
	std::cout << std::endl << f << std::endl;
}

static void test6()
{
	std::cout << CYAN"------------------------------------------------------------" << std::endl;
	std::cout << CYAN BOLD"         TEST 6️⃣ : Invalid Bureaucrat creation           " RESET << std::endl;
	std::cout << CYAN"------------------------------------------------------------" << std::endl;

	try
	{
		Bureaucrat ultra("Ultra", 0);
		std::cout << ultra << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "❌ Bureaucrat error: " << e.what() << std::endl;
	}
}

int main()
{
	handleExceptions(test1);
	std::cout << std::endl;
	
	handleExceptions(test2);
	std::cout << std::endl;
	
	handleExceptions(test3);
	std::cout << std::endl;
	
	handleExceptions(test4);
	std::cout << std::endl;
	
	handleExceptions(test5);
	std::cout << std::endl;

	handleExceptions(test6);
	std::cout << std::endl;

	std::cout << "\n✅ End of tests." << std::endl;
	
	return (0);
}

