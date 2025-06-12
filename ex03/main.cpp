/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:07:32 by alex              #+#    #+#             */
/*   Updated: 2025/06/12 16:48:09 by alfreire         ###   ########.fr       */
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
	Intern junior;

	//AForm *shrub = junior.makeForm("shrubbery creation", "Backyard");
	AForm *robot = junior.makeForm("robotomy request", "Bender");
	AForm *pardon = junior.makeForm("presidential pardon", "Intern");
	AForm *unknown = junior.makeForm("coffee making", "Intern");

	std::cout << std::endl;

	Bureaucrat boss("Boss", 1);

	Intern j2(junior);
	Intern j3;
	Intern j4;

	j4 = j3 = j2;
	AForm *shrub = j4.makeForm("shrubbery creation", "Backyard");

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