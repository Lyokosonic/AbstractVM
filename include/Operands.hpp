/*
** EPITECH PROJECT, 2020
** Operands.hpp
** File description:
** Operands
*/

#ifndef OPERANDS_HPP_
#define OPERANDS_HPP_

#include "IOperands.hpp"
#include <string>

template <class T>
class Operands : public IOperand{
	public:
		Operands(eOperandType type, const std::string &value);
		~Operands();
		eOperandType getPrecision(const IOperand &rhs) const;
		virtual std::string toString() const; // string that represents the instance
		virtual eOperandType getType() const; // returns the type of instance
		virtual IOperand *operator+(const IOperand &rhs) const; // sum
		virtual IOperand *operator-(const IOperand &rhs) const; // diff
		virtual IOperand *operator*(const IOperand &rhs) const; // mul
		virtual IOperand *operator/(const IOperand &rhs) const; // div
		virtual IOperand *operator%(const IOperand &rhs) const; // mod

	private:
		eOperandType _opType;
		T _value;
};

#endif /* !OPERANDS_HPP_ */
