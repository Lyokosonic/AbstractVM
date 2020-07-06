/*
** EPITECH PROJECT, 2020
** AbstractVm.cpp
** File description:
** Main program to execute
*/

#include "../include/AbstractVm.hpp"
#include "../include/Exceptions.hpp"
#include "../include/Commands.hpp"
#include <string>

AbstractVm::AbstractVm(int argc, char const *argv[]) : _type(NONE)
{
	if (argc == 2)
		_parser.getFileContent(std::string(argv[1]), _asmContent);
	else if (argc == 1)
		_parser.readInput(_asmContent);
	else
		throw AVMException::ArgumentException("Too much arguments");
}

AbstractVm::~AbstractVm()
{
}

void AbstractVm::run(void)
{
	Commands cmd(_stack);

	for (auto &&line : _asmContent) {
		_parser.parseCmd(line, _cmd);
		if (!cmd.checkCmd(_cmd))
			throw AVMException::CommandException(_cmd + ": Invalid instruction");
		_parser.parseType(line, _type);
		_parser.parseValue(line, _value);
		cmd.execCmd(_cmd, _value, _type);
	}
}
