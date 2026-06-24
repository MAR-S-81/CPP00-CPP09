/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:56:47 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 13:29:14 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()  : AForm("RobotomyRequestForm", 72, 45){
	this->_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45){
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src )  : AForm(src){
	this->_target = src._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs ) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeExec()) {
        throw AForm::GradeTooLowException();
	}
	if (getSign() == false) {
		throw AForm::NotSignedException();
	}
	std::cout << "* drrrrr drrrrr... *" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
	} 
	else {
		std::cout << "The robotomy of " << this->_target << " failed.." << std::endl;
	}
}