/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:57:27 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 15:38:34 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
}

Intern::Intern( Intern const &src ){
	(void)src;
}

Intern &Intern::operator=( Intern const &rhs ) {
	(void)rhs;
    return *this;
}

Intern::~Intern(){
}

AForm* Intern::makeRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makePresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form, std::string target) {
	std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon" };
	AForm* (Intern::*funcs[3])(std::string) = { &Intern::makeRobotomy, &Intern::makeShrubbery, &Intern::makePresidential };
	for (int i = 0; i <= 2; i++) {
		if (form == formNames[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cout << "Error: form name doesn't exist " << form << std::endl;
	return NULL;
}