/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:35 by alex              #+#    #+#             */
/*   Updated: 2025/05/23 16:18:15 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExec(150) {}

Form::~Form(){}

Form::Form(const std::string &name, int gradetosign, int gradetoexec) : name(name), isSigned(false),
gradeToSign(gradetosign), gradeToExec(gradetoexec)
{
	if (gradetosign > 150 || gradetoexec > 150)
		throw GradeTooLowException();
	else if (gradetosign < 1 || gradetoexec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
gradeToExec(other.gradeToExec) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;	
}

const std::string &Form::getName() const{
	return name;
}

bool Form::getIssigned() const{
	return isSigned;
}

int Form::getGradetosign() const{
	return gradeToSign;
}

int Form::getGradetoexec() const{
	return gradeToExec;
}

void Form::beSigned(const Bureaucrat &bu)
{
	if (bu.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is Too High.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low.";
}

std::ostream &operator<<(std::ostream &os, const Form &fo)
{
	os << "Form Name: " << fo.getName() << '\n'
	<< "Signed: ";
	if (fo.getIssigned())
		os << "Yes";
	else
		os << "No";
	os << '\n'
	<< "Grade to Sign: " << fo.getGradetosign() << '\n'
	<< "Grade to Execute: " << fo.getGradetoexec() << std::endl;
	return os;
}