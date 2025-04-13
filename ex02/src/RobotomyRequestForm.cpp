/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:45:24 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/13 10:06:30 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Colors.hpp"


RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("Default")
{
	std::cout << MAGENTA << "RobotomyRequestForm 🏗 Constructor called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << MAGENTA << "RobotomyRequestForm 🏗 Constructor called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), target(src.target)
{
	std::cout << MAGENTA << "RobotomyRequestForm 🏗 Copy Constructor called." << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
	{
		std::cout << YELLOW << "⚠️ Self-assignment detected, no changes made!" << RESET << std::endl;
		return (*this);
	}
	this->target = src.target;
	std::cout << MAGENTA << "RobotomyRequestForm © Copy Assignment operator called." << RESET << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm 🧨 Destructor called." << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "💥 BRRRRRRRRRRRRRRR... Drilling noises...\n";

	// std::srand(std::time(0)); // Seed the random number generator
	if (std::rand() % 2 != 0)
		std::cout << "❌ " << this->target << " has been robotomized unsuccessfully!" << std::endl;
	else
		std::cout << "✅ " << this->target << " has been robotomized successfully!" << std::endl;
	}
