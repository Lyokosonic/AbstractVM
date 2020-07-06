/*
** EPITECH PROJECT, 2020
** Misc.hpp
** File description:
** Misc
*/

#ifndef MISC_HPP_
#define MISC_HPP_

#include <string>

class Misc {
	public:
		Misc();
		~Misc();
		std::string removeTrailingZero(const std::string &str);
		std::string round(std::string nbr) const;

	private:
		void _getPrecision(std::string &str, int &precision) const;
		void _roundNbr(std::string &str, int precision) const;
};

#endif /* !MISC_HPP_ */
