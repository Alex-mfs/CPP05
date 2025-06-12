/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:43 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 18:29:43 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
	public:
		virtual ~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		const std::string &getName() const;// I only use const in this case because it's a reference, and a reference must be constant to prevent the original name from being modified
		bool getIssigned() const;
		int getGradetosign() const;
		int getGradetoexec() const;

		void beSigned(const Bureaucrat &bu);

		void execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
	protected:
		AForm();
		AForm(const std::string &name, int gradetosign, int gradetoexec);
		virtual void trytoexec() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &fo);