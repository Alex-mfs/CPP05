/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:06:03 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 17:17:16 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Alex", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		std::cout << "my name is " << a.getName() << " and my grade is " << a.getGrade() << std::endl;
		a.incrementGrade(); // exception
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Brenda", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade(); // exception
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat c("Carlos", 0); // exception
		c.getName();
		c.getGrade();
		c.incrementGrade();
		c.decrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat d("Daniel", 151); // exception
		d.getName();
		d.getGrade();
		d.incrementGrade();
		d.decrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
