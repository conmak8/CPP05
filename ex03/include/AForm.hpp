/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:56:10 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/07 16:35:48 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <exception>


class Bureaucrat;

class AForm
{
private:
		std::string const	name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
public:
		//-----------OCF-----------------//
		AForm();																// * Constructor (default)
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);	// * Constructor with parameters
		AForm(const AForm &src);												// * Copy Contructor
		AForm &operator= (const AForm &src);									// * Copy Assignment operator
		virtual ~AForm();																// * Destructor
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
		class FormNotSignedException : public std::exception					// ! <--- ex02
		{
		public:
				const char* what() const noexcept override;
		};
																				//*----------Sign---------//
		void beSigned(const Bureaucrat &b) noexcept(false);
																				//*----------Execute------//  /
		virtual void execute(const Bureaucrat& executor) const = 0;				// ! <--- ex02
};
																				//* -------Overload--------//
std::ostream &operator<< (std::ostream &os, const AForm &f);

#endif // !FORM_HPP
