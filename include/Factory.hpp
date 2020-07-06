/*
** EPITECH PROJECT, 2020
** Factory.hpp
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IOperands.hpp"
#include <string>
#include <map>
#include <functional>

class Factory {
	public:
		Factory();
		~Factory();
		static IOperand *createOperand(eOperandType type, const std::string &value);

	private:
		std::map<eOperandType, std::function<IOperand *(const std::string &value)>> opList;
		IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std::string &value);
        IOperand *createInt32(const std::string &value);
        IOperand *createFloat(const std::string &value);
        IOperand *createDouble(const std::string &value);
        IOperand *createBigDecimal(const std::string &value);
};

#endif /* !FACTORY_HPP_ */
