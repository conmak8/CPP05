/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:30:41 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/14 18:09:25 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/Colors.hpp"


Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(Intern const &src)  // ? check if this is correct
{
	(void)src;
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// * solution old C-style with function pointers
// AForm* createShrubberyForm(const std::string &target)
// {
// 	return new ShrubberyCreationForm(target);
// }

// AForm* createRobotomyForm(const std::string &target)
// {
// 	return new RobotomyRequestForm(target);
// }

// AForm* createPresidentialForm(const std::string &target)
// {
// 	return new PresidentialPardonForm(target);
// }

// solutioin using Lambda expressions

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string formNames[3] = {"robotomy request", 
								"presidential pardon", 
								"shrubbery creation"};
								
	AForm* (*creators[3])(const std::string &) =
	{
		[](const std::string &target) -> AForm* { return new RobotomyRequestForm(target); },
		[](const std::string &target) -> AForm* { return new PresidentialPardonForm(target); },
		[](const std::string &target) -> AForm* { return new ShrubberyCreationForm(target); }
	};

	// * solution old C-style with function pointers
	// AForm* (*creators[3])(const std::string &) =
	// {
	// 	createRobotomyForm,
	// 	createPresidentialForm,
	// 	createShrubberyForm
	// };
	
	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << GREEN "🧙 Intern creates \"" << formName << "\" form targeting \"" << target << "\"" RESET << std::endl;
			return creators[i](target);
		}
	}

	std::cerr << RED "❌ Intern: Unknown form \"" << formName << "\"." RESET << std::endl;
	return nullptr;
}
