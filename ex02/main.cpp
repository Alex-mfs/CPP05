/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:07:32 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 18:50:37 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

void test_form(const std::string& title, AForm& form, Bureaucrat& signer, Bureaucrat& executor) {
	std::cout << "\n=== " << title << " ===\n\n";
	std::cout << form << std::endl;
	std::cout << "Signer: " << signer << "\nExecutor: " << executor << "\n";

	signer.signForm(form);
	executor.executeForm(form);
}

int main()
{
	// Shrubbery MIN: sign=145, exec=137
	try{
		Bureaucrat shrubSigner("ShrubSigner", 145);
		Bureaucrat shrubExecutor("ShrubExecutor", 137);
		ShrubberyCreationForm shrub("backyard");
		test_form("Shrubbery by valid signer and executor", shrub, shrubSigner, shrubExecutor);
	} catch (std::exception & e){
		std::cout << "Shrubbery test failed because " << e.what() << std::endl;
		return 1;
	}

	// Robotomy MIN: sign=72, exec=45
	try{
		Bureaucrat roboSigner("RoboSigner", 72);
		Bureaucrat roboExecutor("RoboExecutor", 45);
		RobotomyRequestForm robot("patient Zero");
		test_form("Robotomy by valid signer and executor", robot, roboSigner, roboExecutor);
	} catch (std::exception & e){
		std::cout << "\nrobot test failed because " << e.what() << std::endl;
		return 1;
	}

	// Presidential MIN: sign=25, exec=5
	try {
		Bureaucrat pardonSigner("PardonSigner", 25);
		Bureaucrat pardonExecutor("PardonExecutor", 5);
		PresidentialPardonForm pardon("Marvin");
		test_form("Pardon by valid signer and executor", pardon, pardonSigner, pardonExecutor);
	} catch (std::exception & e){
		std::cout << "\npresidential test failed because " << e.what() << std::endl;
		return 1;
	}

	// specific Bureaucrats
	Bureaucrat shrubSigner("ShrubSigner", 145);
	Bureaucrat shrubExecutor("ShrubExecutor", 137);
	Bureaucrat roboSigner("RoboSigner", 72);
	Bureaucrat roboExecutor("RoboExecutor", 45);
	Bureaucrat pardonSigner("PardonSigner", 25);
	Bureaucrat pardonExecutor("PardonExecutor", 5);

	// Elite: can do all
	Bureaucrat elite("Elite", 1);

	// Too weak for everything
	Bureaucrat weak("Weak", 150);

	// Forms
	ShrubberyCreationForm shrub("backyard");
	RobotomyRequestForm robot("patient Zero");
	PresidentialPardonForm pardon("Marvin");

	// Execution without signing
	ShrubberyCreationForm notSignedShrub("not_signed");
	std::cout << "\n=== Attempting to execute unsigned form ===\n";
	shrubExecutor.executeForm(notSignedShrub);

	// Signer too weak
	RobotomyRequestForm weakSignForm("Unsignable");
	test_form("Robotomy by weak signer", weakSignForm, weak, roboExecutor);

	// Executor too weak
	PresidentialPardonForm strongSignWeakExec("DeniedExec");
	test_form("Pardon with strong signer and weak executor", strongSignWeakExec, pardonSigner, weak);

	// Same form signed by one, executed by another
	PresidentialPardonForm sharedForm("Delegated");
	pardonSigner.signForm(sharedForm);
	pardonExecutor.executeForm(sharedForm);

	// Copy and assign
	std::cout << "\n=== Testing copy constructor and assignment ===\n";
	RobotomyRequestForm original("Original");
	RobotomyRequestForm copy(original); // Copy constructor
	RobotomyRequestForm assigned;
	assigned = original; // operator=
	elite.signForm(copy);
	elite.executeForm(copy);
	elite.signForm(assigned);
	elite.executeForm(assigned);
	
	
	// Testing polymorphism explicitly using AForm pointers
	// Each AForm* will point to a RobotomyRequestForm (demonstrating runtime polymorphism)
	// Even though the pointer type is AForm*, the correct subclass method will be called
	std::cout << "\n=== Polymorphism test with AForm pointer ===\n";
	std::string robots[5] = {"A", "B", "C", "D", "E"};// naming each 'patient'
	AForm** poly = new AForm*[5];// poly is an array of 5 AForm pointers
	for (int i = 0; i < 5; i++){
		poly[i] = new RobotomyRequestForm(robots[i]);// Upcast: each AForm(base class) pointer is pointing to a robotomyrequestform(derived class).
	}

	for (int i = 0; i < 5; i++){
		std::cout << "\n Patient " << robots[i] << std::endl;
		elite.signForm(*poly[i]);
		elite.executeForm(*poly[i]);// Polymorphism: calls subclass implementation via base pointer
		delete poly[i];// once its used I can delete the specific object pointed by poly.
	}
	delete[] poly;// now I delete the array.

	return 0;
}
