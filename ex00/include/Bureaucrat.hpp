/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:05:12 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/05 19:34:00 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>


class Bureaucrat
{
private:
		std::string const	name;
		int					grade;
public:
		//-----------OCF-----------------//
		Bureaucrat();									// * Constructor (default)
		Bureaucrat(const Bureaucrat &src);				// * Copy Contructor
		Bureaucrat &operator= (const Bureaucrat &src);	// * Copy Assignment operator
		~Bureaucrat();									// * Destructor
		//===============================//
		//-----------Methods------------//
		//----Getter-------------------//
		std::string getName() const;
		int getGrade() const;
		//----------Inc/decrement----//
		void incrementGrade();
		void decrementGrade();
		
};

#endif // !BUREAUCRAT_HPP
