/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:23:49 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/12 14:13:15 by cmakario         ###   ########.fr       */
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
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << MAGENTA << "Form 🏗 Constructor called." << RESET << std::endl;
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
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}
																													//!----------Exceptions------//
const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Form's Grade too high!");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Form's Grade too low!");
}

const char* Form::AlreadySignedException::what() const noexcept
{
	return ("Form is already signed!");
}
																													//!----------Sign---------//
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	if (this->isSigned)
		throw Form::AlreadySignedException();
	this->isSigned = true;
	std::cout << GREEN << this->name << " signed by " << UBR << b.getName() << RESET << std::endl;
	std::cout << std::endl;
}
																													//! -------Overload--------//
std::ostream &operator<< (std::ostream &os, const Form &f)
{
	os << BOLD " Form's name: " RESET << f.getName()
		<< BOLD "\n Signed: " RESET << (f.getIsSigned() ? GREEN "yes" RESET : RED "no" RESET)
		<< BOLD "\n Grade to sign: " RESET << f.getGradeToSign()
		<< BOLD "\n Grade to execute: " RESET << f.getGradeToExecute() << std::endl;
	return (os);
}
