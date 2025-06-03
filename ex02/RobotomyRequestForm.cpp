/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:37:16 by alex              #+#    #+#             */
/*   Updated: 2025/05/30 11:29:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
: AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::trytoexec() const
{
	std::cout << "*drilling noises* BRZZZZ...\n";

	static bool first_seed = true;
	if (first_seed)
	{
		std::srand(std::time(0));// time(0) returns the number os seconds from 1970 unti now, so each initialization of the program will have a different random seed.
		first_seed = false;
	}
	if (std::rand() % 2)// rand will give me a random number, then we see if its odd or even.
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Sorry, Robotomy failed on " << target << "!" << std::endl;
}