/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:56:47 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 14:11:32 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()  : AForm("ShrubberyCreationForm", 145, 137){
	this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137){
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src )  : AForm(src){
	this->_target = src._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs ) {
    if (this != &rhs) {
        this->_target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeExec()) {
        throw AForm::GradeTooLowException();
	}
	if (getSign() == false) {
		throw AForm::NotSignedException();
	}
	std::string out_filename = this->_target + "_shrubbery";
	std::ofstream ofs(out_filename.c_str());
	if (!ofs.is_open()) {
		std::cerr << "Error: Unable to create output file." << std::endl;
        return;
	}
	ofs << "        -=-" << std::endl;
	ofs << "      -=-=-   -=-=-" << std::endl;
	ofs << "cc-=-= \\/-=-=-=-=-" << std::endl;
	ofs << "   -=\\ |/    |/" << std::endl;
	ofs << "    =\\V    \\/" << std::endl;
	ofs << "       \\  /" << std::endl;
	ofs << "        ||" << std::endl;
	ofs << "        ||" << std::endl;
	ofs << "        ||" << std::endl;
	ofs << "       /||" << std::endl;
	ofs.close();
}