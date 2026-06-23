/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:08:20 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/23 15:40:50 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _is_signed(false), _grade_to_exec(1), _grade_to_sign(1) {
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
        throw Form::GradeTooHighException();
    if (_grade_to_exec > 150 || _grade_to_sign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(std::string name, int grade_to_exec, int grade_to_sign) : _name(name), _is_signed(false), _grade_to_exec(grade_to_exec), _grade_to_sign(grade_to_sign) {
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
        throw Form::GradeTooHighException();
    if (_grade_to_exec > 150 || _grade_to_sign > 150)
        throw Form::GradeTooLowException();
}

Form::Form( Form const &src ) : _name(src._name), _is_signed(src._is_signed), _grade_to_exec(src._grade_to_exec), _grade_to_sign(src._grade_to_sign) {
}

Form &Form::operator=( Form const &rhs ) {
    if (this != &rhs) {
        this->_is_signed = rhs._is_signed;
    }
    return *this;
}

Form::~Form(){
}

const std::string &Form::getName() const{
	return (this->_name);
}

bool Form::getSign() const{
	return (this->_is_signed);
}

int Form::getGradeExec() const{
	return (this->_grade_to_exec);
}

int Form::getGradeSign() const{
	return (this->_grade_to_sign);
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

void Form::beSigned(const Bureaucrat &worker) {
	if (worker.getGrade() > this->_grade_to_sign)
		throw Form::GradeTooLowException();
	_is_signed = true;
}

std::ostream & operator<<( std::ostream & o, Form const & i ) {
    o << "Form name: " << i.getName() << std::endl;
    o << "Is signed: " << i.getSign() << std::endl;
    o << "Grade required to sign: " << i.getGradeSign() << std::endl;
    o << "Grade required to execute: " << i.getGradeExec() << std::endl;
    return o;
}