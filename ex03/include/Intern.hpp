/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:47:51 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/14 15:35:45 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>

class Intern
{
public:
	//-----------OCF-----------------//
	Intern();																	// * Constructor (default)
	Intern(const Intern &src);													// * Copy constructor
	Intern &operator=(const Intern &src);										// * Copy Assignment operator
	~Intern();																	// * Destructor
	//===============================//
																				//*-----------Methods------------//
	AForm* makeForm(const std::string &formName, const std::string &target) const;
};

#endif // !INTERN_HPP