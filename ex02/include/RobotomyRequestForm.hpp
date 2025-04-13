/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:57:23 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/13 01:56:30 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <cstdlib> // for rand()
# include <ctime>   // for time()

class RobotomyRequestForm : public AForm
{
private:
	std::string	target;
public:
	//-----------OCF-----------------//
	RobotomyRequestForm();												// * Constructor (default)
	RobotomyRequestForm(const std::string &target);						// * Constructor with parameters	
	RobotomyRequestForm(const RobotomyRequestForm &src);				// * Copy constructor
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);		// * Copy Assignment operator
	~RobotomyRequestForm();												// * Destructor
		//===============================//
																		//*-----------Methods------------//
																		//*----Execute-----------------//
	void execute(Bureaucrat const &executor) const override;
};

#endif // !ROBOTOMYREQUESTFORM_HPP
