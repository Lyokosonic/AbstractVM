/*
** EPITECH PROJECT, 2020
** Commands.hpp
** File description:
** Commands
*/

#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

#include "IOperands.hpp"
#include "utils/Misc.hpp"
#include <list>
#include <map>
#include <functional>
#include <string>
#include <vector>

class Commands {
	public:
		Commands(std::list<const IOperand *> &stack);
		~Commands();

		void loadCmdFunctions(void);
		void loadCmdsList(void);
		bool checkCmd(const std::string cmdParsed);
		void execCmd(const std::string cmdParsed, const std::string &value, eOperandType opType);

		void pushCmd(const std::string &val, eOperandType type);
		void popCmd(const std::string &val, eOperandType type);
		void clearCmd(const std::string &val, eOperandType type);
		void dupCmd(const std::string &val, eOperandType type);
		void swapCmd(const std::string &val, eOperandType type);
		void dumpCmd(const std::string &val, eOperandType type);
		void assertCmd(const std::string &val, eOperandType type);
		void addCmd(const std::string &val, eOperandType type);
		void subCmd(const std::string &val, eOperandType type);
		void mulCmd(const std::string &val, eOperandType type);
		void divCmd(const std::string &val, eOperandType type);
		void modCmd(const std::string &val, eOperandType type);
		void loadCmd(const std::string &val, eOperandType type);
		void storeCmd(const std::string &val, eOperandType type);
		void printCmd(const std::string &val, eOperandType type);
		void exitCmd(const std::string &val, eOperandType type);

	private:
		std::map<std::string, std::function<void (const std::string, eOperandType)>> _cmds;
		std::list<const IOperand *> &_stack;
		std::vector<std::string> _cmdsList;
		Misc _utils;
};

#endif /* !COMMANDS_HPP_ */
