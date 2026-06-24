/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:51:18 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 12:54:32 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm( ShrubberyCreationForm const &src );
    ShrubberyCreationForm &operator=( ShrubberyCreationForm const & rhs );
    ~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
};

#endif