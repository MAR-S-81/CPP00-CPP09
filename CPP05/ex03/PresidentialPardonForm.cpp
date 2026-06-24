/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:56:47 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 13:29:14 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()  : AForm("PresidentialPardonForm", 25, 5){
	this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5){
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src )  : AForm(src){
	this->_target = src._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs ) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeExec()) {
        throw AForm::GradeTooLowException();
	}
	if (getSign() == false) {
		throw AForm::NotSignedException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}