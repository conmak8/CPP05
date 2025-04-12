/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:18:30 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/12 14:12:50 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Colors.hpp"


																															// !-----------OCF-----------------//
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default", 145, 137), target("Default")
{
	std::cout << MAGENTA << "ShrubberyCreationForm 🏗 Constructor called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << MAGENTA << "ShrubberyCreationForm 🏗 Constructor called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), target(src.target)
{
	std::cout << MAGENTA << "ShrubberyCreationForm 🏗 Copy Constructor called." << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &src)
{
	if (this == &src)
	{
		std::cout << YELLOW << "⚠️ Self-assignment detected, no changes made!" << RESET << std::endl;
		return (*this);
	}
	this->target = src.target;
	std::cout << MAGENTA << "ShrubberyCreationForm © Copy Assignment operator called." << RESET << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm 🧨 Destructor called." << RESET << std::endl;
}

																															// !----Execute-----------------//
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outfile(this->target + "_shrubbery");
	if (!outfile)
	{
		std::cerr << RED << "Error: Could not open file." << RESET << std::endl;
		return;
	}
	outfile << "       🌲      \n"
			<< "      🌲🌲🌲     \n"
			<< "     🌲🌲🌲🌲🌲    \n"
			<< "    🌲🌲🌲🌲🌲🌲🌲   \n"
			<< "       ||      \n"
			<< "       ||      \n";
	outfile.close();
	std::cout << GREEN << "ShrubberyCreationForm: Shrubbery created in " << this->target + "_shrubbery" << RESET << std::endl;
}
