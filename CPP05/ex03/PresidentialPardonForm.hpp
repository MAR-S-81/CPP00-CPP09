/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:51:18 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 13:43:45 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
    PresidentialPardonForm( PresidentialPardonForm const &src );
    PresidentialPardonForm &operator=( PresidentialPardonForm const & rhs );
    ~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};

#endif