/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:56:56 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/15 00:48:08 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>


class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	//-----------OCF-----------------//
	PresidentialPardonForm();												// * Constructor (default)
	PresidentialPardonForm(std::string target);								// * Constructor (with parameters)
	PresidentialPardonForm(const PresidentialPardonForm &src);				// * Copy constructor
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);	// * Assignment operator overload
	~PresidentialPardonForm();												// * Destructor
			//===============================//
																			//*-----------Methods------------//
																			//*----Execute-----------------//
	void execute(const Bureaucrat &executor) const noexcept(false) override;
};

#endif // !PRESIDENTIALPARDONFORM_HPP
