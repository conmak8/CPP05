/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:05:12 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/14 23:19:16 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>


class AForm;

class Bureaucrat
{
private:
		std::string const	name;
		int					grade;
public:
		//-----------OCF-----------------//
		Bureaucrat();									// * Constructor (default)
		Bureaucrat(const std::string &name, int grade);	// * Constructor with parameters
		Bureaucrat(const Bureaucrat &src);				// * Copy Contructor
		Bureaucrat &operator= (const Bureaucrat &src);	// * Copy Assignment operator
		~Bureaucrat();									// * Destructor
		//===============================//
														//*-----------Methods------------//
														//*----Getter-------------------//
		std::string getName() const;
		int getGrade() const;
														//*----------Inc/decrement-----//
		void incrementGrade();
		void decrementGrade();
														//* -------Exceptions----------//
		class GradeTooHighException : public std::exception
		{
		public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
		public:
				const char* what() const noexcept override;
		};
														// * --------Sign---------//
		void signForm(AForm &form) noexcept(false);
														// * --------Execute------//
		void executeForm(const AForm &form) const;		// ! <--- ex02

};
														//* -------Overload--------//
	std::ostream &operator<< (std::ostream &os, const Bureaucrat &b);

#endif // !BUREAUCRAT_HPP
