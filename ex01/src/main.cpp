/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:25 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/07 09:47:33 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "../include/Colors.hpp"



int main()
{
	std::cout << "🎯 Creating valid Bureaucrats...\n";
	try
	{
		Bureaucrat bob("Bob", 42);
		Bureaucrat alice("Alice", 1);
		Bureaucrat chad("Chad", 150);
		
		std::cout << std::endl;
		std::cout << bob << std::endl;
		std::cout << alice << std::endl;
		std::cout << chad << std::endl;
		
		std::cout << "\n🔼 Trying to promote Alice (already grade 1)...\n";
		alice.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "💥 Exception: " << e.what() << "\n";
	}
	
	std::cout << "\n🔽 Trying to demote Chad (already grade 150)...\n";
	try
	{
		Bureaucrat chad("Chad", 150);
		chad.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "💥 Exception: " << e.what() << "\n";
	}

	std::cout << "\n🚫 Creating invalid Bureaucrats...\n";
	try
	{
		Bureaucrat errorGuy("TooElite", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "💥 Exception: " << e.what() << "\n";
	}
	
	try
	{
		Bureaucrat errorGal("TooLow", 200);
	}
	catch (std::exception& e)
	{
		std::cerr << "💥 Exception: " << e.what() << "\n";
	}
	
	std::cout << "\n✅ Everything tested! Goodbye!\n";
	return 0;
}


// nice TEST with framework to test each case

// Old style function pointer **type** - avoid.  https://cppformortals.com/2020/03/16/function-pointers/
// typedef void (*RunTest)();
// New style function pointer type - preferred.
// using RunTest = void (*)(); 

// static void handleExceptions(RunTest testCase) {

// 	try {
// 		testCase();
// 	}
// 	catch (const std::exception& e) {
// 		std::cout << "❗ Exception found: " << e.what() << std::endl;
// 	}
// }

// static void test1() {

// 	Bureaucrat a;
// 	Bureaucrat mk("Mary Kate", 42);
// 	Bureaucrat t("Tom", 100);
// 	Bureaucrat copy(mk); //for copy constructor call

// 	std::cout << a << mk << t << copy;
// }

// static void test2() {

// 	Bureaucrat a;
// 	Bureaucrat mk("Mary Kate", 42);
// 	Bureaucrat t("Tom", 100);
// 	Bureaucrat s("Stefan", 5);

// 	std::cout << ("Initial state of our bureaucrats: ") << std::endl;
// 	std::cout << mk << t << s;
	
// 	mk.incrementGrade();
// 	t.decrementGrade();
// 	s = a; //for assignment operator call
// 	s.incrementGrade();
// 	std::cout << ("State after the grade modifications: ") << std::endl;
// 	std::cout << mk << t << s;
// }

// static void test3() {

// 	Bureaucrat a("Bob", 151); // too low
// 	Bureaucrat b("Elsa", 0); // too high
// 	std::cout << a << b;
// }

// static void test4() {
	
// 	Bureaucrat a("Anna", 1); // after increment too high
// 	a.incrementGrade();
// 	std::cout << a;
// }

// static void test5() {

// 	Bureaucrat a("Katerina", 150); // after decrement too low
// 	a.decrementGrade();
// 	std::cout << a;
// }

// int main() {
	
// 	std::cout << (("\nTEST 1️⃣ : Constructing bureaucrats with valid grades")) << std::endl;
// 	std::cout << ("------------------------------------------------------") << std::endl;
// 	handleExceptions(test1);

// 	std::cout << (("\nTEST 2️⃣ : Modifying the grades")) << std::endl;
// 	std::cout << ("------------------------------------------------------") << std::endl;
// 	handleExceptions(test2);

// 	std::cout << (("\nTEST 3️⃣ : Constructing bureaucrats with ")) 
// 				<< (("invalid")) << ((" grades")) << std::endl;
// 	std::cout << ("------------------------------------------------------") << std::endl;
// 	handleExceptions(test3);

// 	std::cout << (("\nTEST 4️⃣ : Increment Grade to out of range ")) << std::endl;
// 	std::cout << ("------------------------------------------------------") << std::endl;
// 	handleExceptions(test4);

// 	std::cout << (("\nTEST 5️⃣ : Decrement Grade to out of range ")) << std::endl;
// 	std::cout << ("------------------------------------------------------") << std::endl;
// 	handleExceptions(test5);

// 	return 0;
// }
