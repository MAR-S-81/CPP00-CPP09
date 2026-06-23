/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:08:31 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/23 15:40:03 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
	bool _is_signed;
	const int _grade_to_exec;
	const int _grade_to_sign;
public:
    Form();
	Form(std::string name, int grade_to_signed, int grade_to_exec);
    Form( Form const &src );
    Form &operator=( Form const & rhs );
    ~Form();

	const std::string &getName() const;
	bool getSign() const;
	int getGradeSign() const;
	int getGradeExec() const;
	
	void beSigned(Bureaucrat const &worker);

	class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
	class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator << ( std::ostream & o, Form const & i );

#endif