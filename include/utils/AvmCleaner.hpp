/*
** EPITECH PROJECT, 2020
** AvmCleaner.hpp
** File description:
** AvmCleaner
*/

#ifndef AVMCLEANER_HPP_
#define AVMCLEANER_HPP_

#include <string>
#include <vector>

class AvmCleaner {
	public:
		AvmCleaner();
		~AvmCleaner();
    	void trim(std::string &str);
        void reduce(std::string &str, const std::string elem);
        void clean(std::vector<std::string> &fileVector);

	private:
		const std::string _whitespace = " \t";
};

#endif /* !AVMCLEANER_HPP_ */
