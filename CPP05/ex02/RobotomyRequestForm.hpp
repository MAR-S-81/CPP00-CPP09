/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:51:18 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 13:43:45 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
    RobotomyRequestForm( RobotomyRequestForm const &src );
    RobotomyRequestForm &operator=( RobotomyRequestForm const & rhs );
    ~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};

#endif