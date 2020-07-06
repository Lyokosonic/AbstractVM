/*
** EPITECH PROJECT, 2020
** Parser.hpp
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "IOperands.hpp"
#include "utils/AvmCleaner.hpp"
#include <string>
#include <vector>
#include <map>
#include <string>

class Parser {
	public:
		Parser();
		~Parser();
		void loadTypes(void);
		eOperandType getTypeEnum(const std::string &type);
		void parseCmd(const std::string line, std::string &cmdParsed);
		void parseType(const std::string line, eOperandType &typeParsed);
		void parseValue(const std::string line, std::string &valueParsed);
		void getFileContent(const std::string fileName, std::vector<std::string> &lines);
		void readInput(std::vector<std::string> &vect);

	private:
		AvmCleaner _clean;
		std::map<std::string, eOperandType> _types;
};

#endif /* !PARSER_HPP_ */
