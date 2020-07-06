/*
** EPITECH PROJECT, 2020
** AbstractVm.cpp
** File description:
** Main program class
*/

#ifndef ABSTRACTVM_HPP_
#define ABSTRACTVM_HPP_

#include "Parser.hpp"
#include <vector>
#include <list>

class AbstractVm {
	public:
		AbstractVm(int argc, char const *argv[]);
		~AbstractVm();

		void run(void);

	private:
		Parser _parser;
		std::vector<std::string> _asmContent;
		std::list<const IOperand *> _stack;
		std::string _cmd;
		eOperandType _type;
		std::string _value;

};

#endif /* !ABSTRACTVM_HPP_ */
