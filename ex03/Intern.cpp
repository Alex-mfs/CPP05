/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:20:54 by alex              #+#    #+#             */
/*   Updated: 2025/06/12 16:41:57 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

// Factory functions must have signature: AForm *something(const std::string &)
// its usefull when we dont know which concrete subclass will be called
static AForm *makeShrub(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm *makeRobot(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *makePardon(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	// Each formName maps to a specific factory function (runtime polymorphism)
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	// AForm* is the type that the function returns, (*fptr)(...) means that its a pointer to a function, and the (...) is the signature of arguments the fucntion.
	// so when I do *fptr[3] I create an array of 3 pointers, and each of this pointers is a pointer to a function.
	AForm* (*fptr[3])(const std::string &);// means I am creating an array of 3 funtion pointers that point to this fucntion parameter signatures and returns an AForm pointer.
	fptr[0] = makeShrub;
	fptr[1] = makeRobot;
	fptr[2] = makePardon;

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return fptr[i](target); // Upcasting to AForm*
		}
	}
	std::cout << "Intern couldn't find form type: " << formName << std::endl;
	return NULL;
}
