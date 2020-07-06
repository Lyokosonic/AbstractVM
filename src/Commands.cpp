/*
** EPITECH PROJECT, 2020
** Commands.cpp
** File description:
** Commands
*/

#include "../include/Commands.hpp"
#include "../include/Exceptions.hpp"
#include "../include/Factory.hpp"
#include <iostream>

Commands::Commands(std::list<const IOperand *> &stack) : _stack(stack)
{
	loadCmdFunctions();
	loadCmdsList();
}

Commands::~Commands()
{
}

void Commands::loadCmdFunctions(void)
{
	_cmds.emplace("push", std::bind(&Commands::pushCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("pop", std::bind(&Commands::popCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("clear", std::bind(&Commands::clearCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("dup", std::bind(&Commands::dupCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("swap", std::bind(&Commands::swapCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("dump", std::bind(&Commands::dumpCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("assert", std::bind(&Commands::assertCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("add", std::bind(&Commands::addCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("sub", std::bind(&Commands::subCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("mul", std::bind(&Commands::mulCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("div", std::bind(&Commands::divCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("mod", std::bind(&Commands::modCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("load", std::bind(&Commands::loadCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("store", std::bind(&Commands::storeCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("print", std::bind(&Commands::printCmd, this, std::placeholders::_1, std::placeholders::_2));
	_cmds.emplace("exit", std::bind(&Commands::exitCmd, this, std::placeholders::_1, std::placeholders::_2));
}

void Commands::loadCmdsList(void)
{
	for (auto &&cmd : _cmds) {
		_cmdsList.push_back(cmd.first);
	}
}

bool Commands::checkCmd(const std::string cmdParsed)
{
	if (_cmds.find(cmdParsed) == _cmds.end())
		return false;
	return true;
}

void Commands::execCmd(const std::string cmdParsed, const std::string &value, eOperandType opType)
{
	for (auto &&cmd : _cmds) {
		if (cmd.first == cmdParsed) {
			_cmds[cmd.first](value, opType);
			return;
		}
	}
}

void Commands::pushCmd(const std::string &val, eOperandType type)
{
	_stack.push_front(Factory::createOperand(type, val));
}

void Commands::popCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	if (_stack.empty())
		throw AVMException::ArgumentException("pop");
	delete _stack.front();
	_stack.pop_front();
}

void Commands::clearCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	_stack.clear();
}

void Commands::dupCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	for (auto &&value : _stack)
		std::cout << value << std::endl;
}

void Commands::swapCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	if (_stack.size() < 2)
		throw AVMException::CommandException("Can not swap an empty stack list");
	auto it2 = _stack.begin();
	auto it1 = it2++;
	std::swap(*it1, *it2);
}

void Commands::dumpCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	std::list<const IOperand*>::iterator i = _stack.begin();
		while (i != _stack.end())
			std::cout << _utils.round((*i++)->toString()) << std::endl;
}

void Commands::assertCmd(const std::string &val, eOperandType type)
{
	const std::string firstVal = _utils.removeTrailingZero((*_stack.begin())->toString());

	if (type != (*_stack.begin())->getType())
		throw AVMException::CommandException("Asset error on different types");
	if (val != firstVal)
		throw AVMException::CommandException("Asset error on different values");
}

void Commands::addCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	if (_stack.size() < 2)
		throw AVMException::CommandException("Cannot add an empty stack list");
	const IOperand *nbr1 = _stack.front();
	_stack.pop_front();
	const IOperand *nbr2 = _stack.front();
	_stack.pop_front();
	_stack.push_front(*nbr1 + *nbr2);
	delete nbr1;
	delete nbr2;
}

void Commands::subCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	if (_stack.size() < 2)
		throw AVMException::CommandException("Cannot sub an empty stack list");
	const IOperand *nbr1 = _stack.front();
	_stack.pop_front();
	const IOperand *nbr2 = _stack.front();
	_stack.pop_front();
	_stack.push_front(*nbr1 - *nbr2);
	delete nbr1;
	delete nbr2;
}

void Commands::mulCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	if (_stack.size() < 2)
		throw AVMException::CommandException("Cannot multiply an empty stack list");
	const IOperand *nbr1 = _stack.front();
	_stack.pop_front();
	const IOperand *nbr2 = _stack.front();
	_stack.pop_front();
	_stack.push_front(*nbr1 * *nbr2);
	delete nbr1;
	delete nbr2;
}

void Commands::divCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	if (_stack.size() < 2)
		throw AVMException::CommandException("Cannot divide an empty stack list");
	const IOperand *nbr1 = _stack.front();
	_stack.pop_front();
	const IOperand *nbr2 = _stack.front();
	_stack.pop_front();
	_stack.push_front(*nbr1 / *nbr2);
	delete nbr1;
	delete nbr2;
}

void Commands::modCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	if (_stack.size() < 2)
		throw AVMException::CommandException("Cannot modulo an empty stack list");
	const IOperand *nbr1 = _stack.front();
	_stack.pop_front();
	const IOperand *nbr2 = _stack.front();
	_stack.pop_front();
	_stack.push_front(*nbr1 % *nbr2);
	delete nbr1;
	delete nbr2;
}

void Commands::loadCmd(const std::string &val, eOperandType type)
{
	(void)type;
	if (_stack.empty())
			throw AVMException::CommandException("Load instruction on empty stack");
	auto i = _stack.begin();
	for (; i != _stack.end(); i++) {
		if (val == (*i)->toString()) {
			_stack.push_front(*i);
			break;
		}
	}
	if (i == _stack.end())
		throw AVMException::CommandException("Can not load register which doesn't exist");
}

void Commands::storeCmd(const std::string &val, eOperandType type)
{
	(void)type;
	if (_stack.empty())
			throw AVMException::CommandException("Store instruction on empty stack");
	auto value1 = _stack.front();
	_stack.pop_front();
	auto i = _stack.begin();
	for (; i != _stack.end(); i++) {
		if ((*i)->toString() == val) {
			_stack.insert(i, value1);
			break;
		}
	}
	if (i == _stack.end())
		throw AVMException::CommandException("Can not store register which doesn't exist");
}

void Commands::printCmd(const std::string &val, eOperandType type)
{
	if ((*_stack.begin())->getType() != INT8)
		assertCmd(val, type);
	std::cout << static_cast<char>(std::stoi((*_stack.begin())->toString())) << std::endl;
}

void Commands::exitCmd(const std::string &val, eOperandType type)
{
	(void)val;
	(void)type;
	for (auto &&op : _stack)
		delete op;
	_stack.clear();
}
