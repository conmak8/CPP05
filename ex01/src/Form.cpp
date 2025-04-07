/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:23:49 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/07 10:51:31 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Colors.hpp"

																													//!-----------OCF-----------------//
Form::Form(): name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << MAGENTA << "Form 🏗 Constructor called." << RESET << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << MAGENTA << "Form 🏗 Constructor called." << RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
	: name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	std::cout << MAGENTA << "Form 🏗 Copy Constructor called." << RESET << std::endl;
}

Form &Form::operator= (const Form &src)
{
	if (this == &src)
	{
		std::cout << YELLOW << "⚠️ Self-assignment detected, no changes made!" << RESET << std::endl;
		return (*this);
	}
	this->isSigned = src.isSigned;
	std::cout << MAGENTA << "Form © Copy Assignment operator called." << RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "Form 🧨 Destructor called." << RESET << std::endl;
}																													//!===============================//
																													//!-----------Methods------------//	
																													//!----Getter-------------------//
std::string Form::getName() const