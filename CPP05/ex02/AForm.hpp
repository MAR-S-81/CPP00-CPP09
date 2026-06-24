/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:08:31 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/23 15:40:03 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string _name;
	bool _is_signed;
	const int _grade_to_exec;
	const int _grade_to_sign;
public:
    AForm();
	AForm(std::string name, int grade_to_signed, int grade_to_exec);
    AForm( AForm const &src );
    AForm &operator=( AForm const & rhs );
    ~AForm();

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
	class NotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator << ( std::ostream & o, AForm const & i );

#endif