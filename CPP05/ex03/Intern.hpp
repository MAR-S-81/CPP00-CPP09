/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:57:17 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 15:12:48 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern
{
private:
	AForm* makeRobotomy(std::string target);
	AForm* makeShrubbery(std::string target);
	AForm* makePresidential(std::string target);
public:
    Intern();
    Intern( Intern const &src );
    Intern &operator=( Intern const & rhs );
    ~Intern();
	
	AForm* makeForm(std::string form, std::string target);
};

#endif