/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:56:10 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/07 20:12:46 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <exception>


class Bureaucrat;

class Form
{
private:
		std::string const	name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
public:
		//-----------OCF-----------------//
		Form();																// * Constructor (default)
		Form(const std::string &name, int gradeToSign, int gradeToExecute);	// * Constructor with parameters
		Form(const Form &src);												// * Copy Contructor
		Form &operator= (const Form &src);									// * Copy Assignment operator
		~Form();															// * Destructor
		//===============================//
																			//*-----------Methods------------//
																			//*----Getter-------------------//
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
																			//*----------Exceptions------//
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
		class AlreadySignedException : public std::exception
		{
		public:
				const char* what() const noexcept override;
		};
																			//*----------Sign---------//
		void beSigned(const Bureaucrat &b);
};
																			//* -------Overload--------//
std::ostream &operator<< (std::ostream &os, const Form &f);

#endif // !FORM_HPP
