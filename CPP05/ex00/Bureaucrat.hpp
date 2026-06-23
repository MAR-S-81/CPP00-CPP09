/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:04:36 by mchesnea          #+#    #+#             */
/*   Updated: 2026/06/23 12:39:24 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat
{
private:
    const std::string _name;
	int _grade;
public:
    Bureaucrat();
	Bureaucrat(std::string name, int grade);
    Bureaucrat( Bureaucrat const &src );
    Bureaucrat &operator=( Bureaucrat const & rhs );
    ~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	
	Bureaucrat &operator++( void );
	Bureaucrat &operator--( void );
	class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
	class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator << ( std::ostream & o, Bureaucrat const & i );

#endif