/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:03:34 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/15 00:51:13 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
		std::string target;
public:
		//-----------OCF-----------------//
		ShrubberyCreationForm();												// * Constructor (default)
		ShrubberyCreationForm(const std::string &target);						// * Constructor with parameters
		ShrubberyCreationForm(const ShrubberyCreationForm &src);				// * Copy Contructor
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &src);	// * Copy Assignment operator
		~ShrubberyCreationForm();												// * Destructor

		//===============================//
																				//*-----------Methods------------//
																				//*----Execute-----------------//
		void execute(const Bureaucrat &executor) const noexcept(false) override;
};

#endif // !SHRUBBERYCREATIONFORM_HPP
