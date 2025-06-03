/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:06:43 by alex              #+#    #+#             */
/*   Updated: 2025/05/23 16:18:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;// name is const so we cant assign a new name, only a new grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bu)
{
	os << bu.getName() << ", bureaucrat grade " << bu.getGrade();
	return os;
}

void Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << name << " couldn't sign " << f.getName() << " because "
		<< e.what() << std::endl;
	}
}