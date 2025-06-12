/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:07:32 by alex              #+#    #+#             */
/*   Updated: 2025/06/05 01:11:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>


int main() {
	Intern someRandomIntern;

	AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "Backyard");
	AForm *robot = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	AForm *unknown = someRandomIntern.makeForm("coffee making", "Intern");

	std::cout << std::endl;

	Bureaucrat boss("Boss", 1);

	if (shrub) {
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}
	if (robot) {
		boss.signForm(*robot);
		boss.executeForm(*robot);
		delete robot;
	}
	if (pardon) {
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}

	if (unknown) {
		boss.signForm(*unknown);
		boss.executeForm(*unknown);
		AForm* a(unknown);
		boss.signForm(*a);
	}
	
	return 0;
}