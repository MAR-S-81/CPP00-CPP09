/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:08:20 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 12:13:44 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _is_signed(false), _grade_to_sign(1), _grade_to_exec(1) {
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
        throw AForm::GradeTooHighException();
    if (_grade_to_exec > 150 || _grade_to_sign > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
        throw AForm::GradeTooHighException();
    if (_grade_to_exec > 150 || _grade_to_sign > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const &src ) : _name(src._name), _is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec) {
}

AForm &AForm::operator=( AForm const &rhs ) {
    if (this != &rhs) {
        this->_is_signed = rhs._is_signed;
    }
    return *this;
}

AForm::~AForm(){
}

const std::string &AForm::getName() const{
	return (this->_name);
}

bool AForm::getSign() const{
	return (this->_is_signed);
}

int AForm::getGradeExec() const{
	return (this->_grade_to_exec);
}

int AForm::getGradeSign() const{
	return (this->_grade_to_sign);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* AForm::NotSignedException::what() const throw() {
	return "This is not signed!";
}

void AForm::beSigned(const Bureaucrat &worker) {
	if (worker.getGrade() > this->_grade_to_sign)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}

std::ostream & operator<<( std::ostream & o, AForm const & i ) {
    o << "AForm name: " << i.getName() << std::endl;
    o << "Is signed: " << i.getSign() << std::endl;
    o << "Grade required to sign: " << i.getGradeSign() << std::endl;
    o << "Grade required to execute: " << i.getGradeExec() << std::endl;
    return o;
}