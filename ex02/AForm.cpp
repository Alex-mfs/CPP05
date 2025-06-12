/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:35 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 18:29:36 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExec(150) {}

AForm::~AForm(){}

AForm::AForm(const std::string &name, int gradetosign, int gradetoexec) : name(name), isSigned(false),
gradeToSign(gradetosign), gradeToExec(gradetoexec)
{
	if (gradetosign > 150 || gradetoexec > 150)
		throw GradeTooLowException();
	else if (gradetosign < 1 || gradetoexec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
gradeToExec(other.gradeToExec) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;	
}

const std::string &AForm::getName() const{
	return name;
}

bool AForm::getIssigned() const{
	return isSigned;
}

int AForm::getGradetosign() const{
	return gradeToSign;
}

int AForm::getGradetoexec() const{
	return gradeToExec;
}

void AForm::beSigned(const Bureaucrat &bu)
{
	if (bu.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is Too High.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low.";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "This Form is Not Signed.";
}

std::ostream &operator<<(std::ostream &os, const AForm &fo)
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

void AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw NotSignedException();
	if (executor.getGrade() > gradeToExec)
		throw GradeTooLowException();
	trytoexec();
}