/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:23 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 18:08:34 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "\n==== Test: making a valid Form ====\n";
	try {
		Form f1("Very important Formulary", 1, 150);
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "==== Test: making a Form with default, assign and copy ====\n";
	Form f1a("Very important Formulary", 1, 149);
	Form f1b;
	std::cout << "f1b with default constructor" << '\n' << f1b << std::endl;
	f1b = f1a;
	std::cout << "f1b after assignment now is" << '\n' << f1b << std::endl;
	Form f1c(f1a);
	std::cout << "f1c created based on f1a" << '\n' << f1c << std::endl;
	
	std::cout << "==== Test: making a Form with invalid grade ====\n";
	try {
		Form f2("invalid_form", 0, 200); // both invalid
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n==== Test: Bureaucrat signs with suficient grade ====\n";
	Bureaucrat alice("Alice", 30);
	Form fA("Formulary A", 50, 100);

	std::cout << alice << std::endl;
	std::cout << fA << std::endl;

	alice.signForm(fA); // should work
	std::cout << fA << std::endl;

	std::cout << "==== Test: Bureaucrat sign with insuficient grade ====\n";
	Bureaucrat bob("Bob", 120);
	Form fB("Formulary B", 100, 100);

	std::cout << bob << std::endl;
	std::cout << fB << std::endl;

	bob.signForm(fB); // should fail
	std::cout << fB << std::endl;

	std::cout << "==== Test: sign a form that is already signed ====\n";
	alice.signForm(fA); // already signed, but the subject dont want us to treat this.

	return 0;
}
