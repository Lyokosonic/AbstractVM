/*
** EPITECH PROJECT, 2020
** Misc.cpp
** File description:
** Misc
*/

#include "../../include/utils/Misc.hpp"

#include <iomanip>
#include <sstream>

Misc::Misc()
{
}

Misc::~Misc()
{
}

std::string Misc::removeTrailingZero(const std::string &str)
{
	char nbr;
	std::string res(str);

	if (res.find(".") == std::string::npos)
		return (res);
	nbr = str[str.length() - 1];
	for (std::string::size_type s = res.length() - 1; s > 0; --s) {
		if (nbr == res[s])
			res.erase(s, 1);
	}
	return (res);
}

void Misc::_getPrecision(std::string &str, int &precision) const
{
	char nbr;
    std::size_t comma;
    std::string digitsAfterComma(str);

    nbr = digitsAfterComma[digitsAfterComma.length() - 1];
    for (std::string::size_type s = digitsAfterComma.length() - 1; s > 0; --s) {
        if (digitsAfterComma[s] == nbr)
            digitsAfterComma.erase(s, 1);
        else
            break;
    }
    comma = digitsAfterComma.find(".");
    digitsAfterComma = digitsAfterComma.substr(comma + 1, str.size() - comma);
    precision = digitsAfterComma.size();
}

void Misc::_roundNbr(std::string &str, int precision) const
{
	std::ostringstream ss;
    double nbr;

    nbr = std::stod(str);
    ss << std::fixed << std::setprecision(precision) << nbr;
    str = ss.str();
}

std::string Misc::round(std::string nbr) const
{
	std::size_t comma;
	std::string res;
	int prescison = 0;

	if ((comma = nbr.find(".")) == std::string::npos)
        return (nbr);
	_getPrecision(nbr, prescison);
	_roundNbr(nbr, prescison);
	return (nbr);
}
