/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:53:52 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/06 14:47:39 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Colors.hpp"

																													//!-----------OCF-----------------//
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << MAGENTA << "Bureaucrat: 🏗 Constructor called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << MAGENTA << "Bureaucrat: 🏗 Constructor called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
	std::cout << MAGENTA << "Bureaucrat: 🏗 Copy Constructor called." << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &src)
{
	if (this == &src)
	{
		std::cout << YELLOW << "⚠️ Self-assignment detected, no changes made!" << RESET << std::endl;
		return (*this);
	}
	this->grade = src.grade; // name is const, so i don't change it
	std::cout << MAGENTA << "Bureaucrat: © Copy Assignment operator called." << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat: 🧨 Destructor called." << RESET << std::endl;
}
																													//!===============================//
																													//!-----------Methods------------//	
																													//!----Getter-------------------//
std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}
																													//!----------Inc/decrement-----//
void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	--this->grade;
	std::cout << GREEN << "Bureaucrat: Grade incremented to " << this->grade << RESET << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	++this->grade;
	std::cout << GREEN << "Bureaucrat: Grade decremented to " << this->grade << RESET << std::endl;
}
																													//! -------Exceptions----------//
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return (RED "Bureaucrat: Grade too high!" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return (RED "Bureaucrat: Grade too low!" RESET);
}
																													//! -------Overload--------//
std::ostream &operator<< (std::ostream &os, const Bureaucrat &b)
{
	os << MAGENTA << "Bureaucrat: " << b.getName() << ", grade: " << b.getGrade() << RESET;
	return (os);
}
