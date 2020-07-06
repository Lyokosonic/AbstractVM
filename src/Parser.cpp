/*
** EPITECH PROJECT, 2020
** Parser.cpp
** File description:
** Parser
*/

#include "../include/Parser.hpp"
#include "../include/Exceptions.hpp"
#include <iostream>
#include <fstream>

Parser::Parser()
{
	loadTypes();
}

Parser::~Parser()
{
}

void Parser::loadTypes(void)
{
	_types.emplace("int8", INT8);
	_types.emplace("int16", INT16);
	_types.emplace("int32", INT32);
	_types.emplace("float", FLOAT);
	_types.emplace("double", DOUBLE);
	_types.emplace("bigdecimal", BIGDECIMAL);
}

eOperandType Parser::getTypeEnum(const std::string &typeParsed)
{
	for (auto &&type : _types) {
        if (typeParsed == type.first)
            return (_types[type.first]);
    }
    throw AVMException::SyntaxException("Invalid type");
}

void Parser::parseCmd(const std::string line, std::string &cmdParsed)
{
	std::size_t cmd;

	cmd = line.find_first_of(" ");
	cmdParsed = line.substr(0, cmd);
}

void Parser::parseType(const std::string line, eOperandType &typeParsed)
{
	std::size_t parenthesis;
    std::size_t space;
    std::string type;

	if ((parenthesis = line.find("(")) == std::string::npos) {
		typeParsed = NONE;
		return;
	}
	if ((space = line.find(" ")) == std::string::npos) {
		typeParsed = NONE;
		return;
	}
	++space;
	type = line.substr(space, parenthesis - space);
	typeParsed = getTypeEnum(type);
}

void Parser::parseValue(const std::string line, std::string &valueParsed)
{
	std::size_t open;
	std::size_t space;
	std::size_t close;

	if ((open = line.find("(")) == std::string::npos) {
		if ((space = line.find(" ")) != std::string::npos)
            valueParsed = line.substr(space + 1, line.size());
        else
            valueParsed = "";
        return;
	}
	if ((close = line.find(")")) == std::string::npos) {
        valueParsed = "";
        return;
    }
	++open;
	valueParsed = line.substr(open, close - open);
}

void Parser::getFileContent(const std::string fileName, std::vector<std::string> &lines)
{
	std::ifstream file(fileName);
	std::string line;
	size_t comment = 0;

	if(!file.is_open())
		throw AVMException::FileException("Cannot open file: " + fileName);
	while (std::getline(file, line)) {
		if ((comment = line.find_first_of(";")) != std::string::npos)
			line.erase(comment, line.size());
		if(!line.empty())
			lines.push_back(line);
	}
	file.close();
	if (lines.empty())
		throw AVMException::FileException("File is empty");
	_clean.clean(lines);
	if (lines.back() != "exit")
		throw AVMException::FileException("No exit command specified");
}

void Parser::readInput(std::vector<std::string> &vect)
{
	std::string line;

	while (getline(std::cin, line) && line != ";;")
		vect.push_back(line);
	if (vect.empty())
		throw AVMException::SyntaxException("Nothing to do");
	_clean.clean(vect);
}
