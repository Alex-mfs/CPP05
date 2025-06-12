/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:06:51 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 16:57:07 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat(const std::string &name, int grade);

		const std::string &getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		
		//nested classes (define a class inside a class), this exceptions only make sense in the Bureacrat class context
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();/* Its a promisse to the compiler that this what() method dont throw exceptions */
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bu);
