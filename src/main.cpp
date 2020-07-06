/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** Main program
*/

#include "../include/AbstractVm.hpp"
#include "../include/Exceptions.hpp"
#include "../include/Parser.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	try {
		AbstractVm abstractVm(argc, argv);

		abstractVm.run();
	} catch(AVMException::Exceptions const &e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
	return (0);
}
