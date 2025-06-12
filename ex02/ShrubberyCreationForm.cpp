/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:25:01 by alex              #+#    #+#             */
/*   Updated: 2025/06/03 18:30:20 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
: AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::trytoexec() const{
	std::ofstream file((target + "_shrubbery").c_str());
	file << "    ccee88oo\n"
	<< "C8O8O8Q8PoOb o8oo\n"
    << "dOB69QO8PdUOpugoO9bD\n"
    << "CgggbU8OU qOp qOdoUOdcb\n"
	<< " 6OuU  /p u gcoUodpP\n"
	<< "   \\\\///  /douUP\n"
	<< "    \\\\////\n"
	<< "    ||||/\\\n"
	<< "    ||||\\/\n"
	<< "    ||||||\n"
	<< "...//||||\\\\...\n";
	file.close();
}