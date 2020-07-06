/*
** EPITECH PROJECT, 2020
** AvmCleaner.cpp
** File description:
** AvmCleaner
*/

#include "../../include/utils/AvmCleaner.hpp"

AvmCleaner::AvmCleaner()
{
}

AvmCleaner::~AvmCleaner()
{
}

void AvmCleaner::trim(std::string &str)
{
	std::size_t beginSpace = 0, lastSpace = 0;

	beginSpace = str.find_first_not_of(_whitespace);
	str.erase(0, beginSpace);
	lastSpace = str.find_last_not_of(_whitespace);
	if (lastSpace != std::string::npos)
		str.erase(lastSpace + 1);
}

void AvmCleaner::reduce(std::string &str, const std::string elem)
{
	std::size_t beginSpace = 0, lastSpace = 0, range = 0;

	beginSpace = str.find_first_of(_whitespace);
	while (beginSpace != std::string::npos) {
		lastSpace = str.find_first_not_of(_whitespace, beginSpace);
		range = lastSpace - beginSpace;
		str.replace(beginSpace, range, elem);
		beginSpace = str.find_first_of(_whitespace, beginSpace + elem.length());
	}
}

void AvmCleaner::clean(std::vector<std::string> &fileVector)
{
	for (unsigned int i = 0; i < fileVector.size(); i++) {
		trim(fileVector[i]);
		reduce(fileVector[i], " ");
		if (fileVector[i].empty())
			fileVector.erase(fileVector.begin() + i--);
	}
}
