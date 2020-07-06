/*
** EPITECH PROJECT, 2020
** IOperands.hpp
** File description:
** Interface operands
*/

#ifndef IOPERANDS_HPP_
#define IOPERANDS_HPP_

#include <string>

enum eOperandType
{
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE,
	BIGDECIMAL,
	NONE
};

class IOperand
{
	public:
		virtual std::string toString() const = 0; // string that represents the instance
		virtual eOperandType getType() const = 0; // returns the type of instance
		virtual IOperand *operator+(const IOperand &rhs) const = 0; // sum
		virtual IOperand *operator-(const IOperand &rhs) const = 0; // diff
		virtual IOperand *operator*(const IOperand &rhs) const = 0; // mul
		virtual IOperand *operator/(const IOperand &rhs) const = 0; // div
		virtual IOperand *operator%(const IOperand &rhs) const = 0; // mod
		virtual ~IOperand() = default;
};

#endif /* !IOPERANDS_HPP_ */
