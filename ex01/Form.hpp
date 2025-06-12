/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:43 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 17:23:48 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
	public:
		Form();
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		Form(const std::string &name, int gradetosign, int gradetoexec);
	
		const std::string &getName() const;// I only use const in this case because it's a reference, and a reference must be constant to prevent the original name from being modified
		bool getIssigned() const;
		int getGradetosign() const;
		int getGradetoexec() const;

		void beSigned(const Bureaucrat &bu);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &fo);