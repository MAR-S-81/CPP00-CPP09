/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:19 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/24 13:59:30 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1){
	if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name(src._name), _grade(src._grade) {
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs ) {
    if (this != &rhs) {
        this->_grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){
}

const std::string &Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

Bureaucrat &Bureaucrat::operator++() {
	if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
	this->_grade--;
    return *this;
}

Bureaucrat &Bureaucrat::operator--() {
	if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
	this->_grade++;
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i ) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
    return o;
}

void Bureaucrat::signForm(AForm &form) {
	try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } 
	catch (std::exception &e) {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
	try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } 
	catch (std::exception &e) {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}