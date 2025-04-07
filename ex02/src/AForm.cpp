/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:23:49 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/07 16:38:49 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

																													//!-----------OCF-----------------//
AForm::AForm(): name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << MAGENTA << "AForm 🏗 Constructor called." << RESET << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << MAGENTA << "AForm 🏗 Constructor called." << RESET << std::endl;
}

AForm::AForm(const AForm &src)
	: name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	std::cout << MAGENTA << "AForm 🏗 Copy Constructor called." << RESET << std::endl;
}

AForm &AForm::operator= (const AForm &src)
{
	if (this == &src)
	{
		std::cout << YELLOW << "⚠️ Self-assignment detected, no changes made!" << RESET << std::endl;
		return (*this);
	}
	this->isSigned = src.isSigned;
	std::cout << MAGENTA << "AForm © Copy Assignment operator called." << RESET << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "AForm 🧨 Destructor called." << RESET << std::endl;
}																													//!===============================//
																													//!-----------Methods------------//	
																													//!----Getter-------------------//
std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}
																													//!----------Exceptions------//
const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("AForm's Grade too high!");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("AForm's Grade too low!");
}

const char* AForm::AlreadySignedException::what() const noexcept
{
	return ("AForm is already signed!");
}

const char* AForm::FormNotSignedException::what() const noexcept													// * <--- ex02
{
	return ("AForm is not signed and cannot be executed!");
}
																													//!----------Sign---------//
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	if (this->isSigned)
		throw AForm::AlreadySignedException();
	this->isSigned = true;
	std::cout << GREEN << this->name << " signed by " << UBR << b.getName() << RESET << std::endl;
	std::cout << std::endl;
}
																													//! -------Overload--------//
std::ostream &operator<< (std::ostream &os, const AForm &f)
{
	os << BOLD " AForm's name: " RESET << f.getName()
		<< BOLD "\n Signed: " RESET << (f.getIsSigned() ? GREEN "yes" RESET : RED "no" RESET)
		<< BOLD "\n Grade to sign: " RESET << f.getGradeToSign()
		<< BOLD "\n Grade to execute: " RESET << f.getGradeToExecute() << std::endl;
	return (os);
}
