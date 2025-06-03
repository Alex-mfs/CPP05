/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:06:03 by alex              #+#    #+#             */
/*   Updated: 2025/05/21 14:08:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Alex", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
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
		Bureaucrat c("Carlos", 0); // exeception
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat d("Daniel", 151); // exception
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
