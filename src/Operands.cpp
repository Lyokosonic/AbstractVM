/*
** EPITECH PROJECT, 2020
** Operands.cpp
** File description:
** Operands
*/

#include "../include/Operands.hpp"
#include "../include/Factory.hpp"
#include "../include/Exceptions.hpp"
#include <string>
#include <sstream>
#include <cmath>

template <typename T>
Operands<T>::Operands(eOperandType type, const std::string &value) : _opType(type)
{
	std::stringstream str(value);

	str >> _value;
}

template <typename T>
Operands<T>::~Operands()
{
}

template <typename T>
eOperandType Operands<T>::getPrecision(const IOperand &rhs) const
{
	eOperandType precision;

	if (_opType > rhs.getType())
		precision = _opType;
	else
		precision = rhs.getType();
	return precision;
}

template <typename T>
std::string Operands<T>::toString() const
{
	return std::to_string(_value);
}

template <typename T>
eOperandType Operands<T>::getType() const
{
	return _opType;
}

template <typename T>
IOperand *Operands<T>::operator+(const IOperand &rhs) const
{
	std::string strVal1 = toString();
	std::string strVal2 = rhs.toString();
	std::stringstream converter(strVal1);
	eOperandType precision = NONE;
	double val1 = 0;
	double val2 = 0;
	double res = 0;

	precision = getPrecision(rhs);
	converter >> val1;
	converter = std::stringstream(strVal2);
	converter >> val2;
	res = val1 + val2;
	return Factory::createOperand(precision, std::to_string(res));
}

template <typename T>
IOperand *Operands<T>::operator-(const IOperand &rhs) const
{
	std::string strVal1 = toString();
	std::string strVal2 = rhs.toString();
	std::stringstream converter(strVal1);
	eOperandType precision = NONE;
	double val1 = 0;
	double val2 = 0;
	double res = 0;

	precision = getPrecision(rhs);
	converter >> val1;
	converter = std::stringstream(strVal2);
	converter >> val2;
	res = val1 - val2;
	return Factory::createOperand(precision, std::to_string(res));
}

template <typename T>
IOperand *Operands<T>::operator*(const IOperand &rhs) const
{
	std::string strVal1 = toString();
	std::string strVal2 = rhs.toString();
	std::stringstream converter(strVal1);
	eOperandType precision = NONE;
	double val1 = 0;
	double val2 = 0;
	double res = 0;

	precision = getPrecision(rhs);
	converter >> val1;
	converter = std::stringstream(strVal2);
	converter >> val2;
	res = val1 * val2;
	return Factory::createOperand(precision, std::to_string(res));
}

template <typename T>
IOperand *Operands<T>::operator/(const IOperand &rhs) const
{
	std::string strVal1 = toString();
	std::string strVal2 = rhs.toString();
	std::stringstream converter(strVal1);
	eOperandType precision = NONE;
	double val1 = 0;
	double val2 = 0;
	double res = 0;

	precision = getPrecision(rhs);
	converter >> val1;
	converter = std::stringstream(strVal2);
	converter >> val2;
	if (val2 == 0)
		throw AVMException::OperandException("Division by 0");
	res = val1 / val2;
	return Factory::createOperand(precision, std::to_string(res));
}

template <typename T>
IOperand *Operands<T>::operator%(const IOperand &rhs) const
{
	std::string strVal1 = toString();
	std::string strVal2 = rhs.toString();
	std::stringstream converter(strVal1);
	eOperandType precision = NONE;
	double val1 = 0;
	double val2 = 0;
	double res = 0;

	precision = getPrecision(rhs);
	converter >> val1;
	converter = std::stringstream(strVal2);
	converter >> val2;
	if (val2 == 0)
		throw AVMException::OperandException("Modulo by 0");
	res = std::fmod(val1, val2);
	return Factory::createOperand(precision, std::to_string(res));
}

template class Operands<char>;
template class Operands<short>;
template class Operands<int>;
template class Operands<float>;
template class Operands<double>;
template class Operands<long double>;
