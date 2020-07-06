/*
** EPITECH PROJECT, 2020
** Factory.cpp
** File description:
** Factory
*/

#include "../include/Factory.hpp"
#include "../include/Operands.hpp"
#include "../include/Exceptions.hpp"
#include <limits>
#include <sstream>

Factory::Factory()
{
	opList.emplace(INT8, std::bind(&Factory::createInt8, this, std::placeholders::_1));
	opList.emplace(INT16, std::bind(&Factory::createInt16, this, std::placeholders::_1));
	opList.emplace(INT32, std::bind(&Factory::createInt32, this, std::placeholders::_1));
	opList.emplace(FLOAT, std::bind(&Factory::createFloat, this, std::placeholders::_1));
	opList.emplace(DOUBLE, std::bind(&Factory::createDouble, this, std::placeholders::_1));
	opList.emplace(BIGDECIMAL, std::bind(&Factory::createBigDecimal, this, std::placeholders::_1));
}

Factory::~Factory()
{
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
	Factory factory;

	if (factory.opList.find(type) == factory.opList.end())
		throw AVMException::OperandException("Unknown operator");
	return factory.opList[type](value);
}

IOperand *Factory::createInt8(const std::string &value)
{
	std::stringstream str(value);
    double res = 0;

    str >> res;
    if (str.fail())
        throw AVMException::MemoryException("Impossible conversion");
    if (res < std::numeric_limits<char>::min())
        throw AVMException::MemoryException("Underflow value");
    if (res > std::numeric_limits<char>::max())
        throw AVMException::MemoryException("Overflow value");
    return (new Operands<char>(INT8, value));
}

IOperand *Factory::createInt16(const std::string &value)
{
	std::stringstream str(value);
    double res = 0;

    str >> res;
    if (str.fail())
        throw AVMException::MemoryException("Impossible conversion");
    if (res < std::numeric_limits<short>::min())
        throw AVMException::MemoryException("Underflow value");
    if (res > std::numeric_limits<short>::max())
        throw AVMException::MemoryException("Overflow value");
    return (new Operands<short>(INT16, value));
}

IOperand *Factory::createInt32(const std::string &value)
{
	std::stringstream str(value);
    double res = 0;

    str >> res;
    if (str.fail())
        throw AVMException::MemoryException("Impossible conversion");
    if (res < std::numeric_limits<int>::min())
        throw AVMException::MemoryException("Underflow value");
    if (res > std::numeric_limits<int>::max())
        throw AVMException::MemoryException("Overflow value");
    return (new Operands<int>(INT32, value));
}

IOperand *Factory::createFloat(const std::string &value)
{
	std::stringstream str(value);
    double res = 0;

    str >> res;
    if (str.fail())
        throw AVMException::MemoryException("Impossible conversion");
    if (res < std::numeric_limits<float>::min())
        throw AVMException::MemoryException("Underflow value");
    if (res > std::numeric_limits<float>::max())
        throw AVMException::MemoryException("Overflow value");
    return (new Operands<float>(FLOAT, value));
}

IOperand *Factory::createDouble(const std::string &value)
{
	std::stringstream str(value);
    double res = 0;

    str >> res;
    if (str.fail())
        throw AVMException::MemoryException("Impossible conversion");
    if (res > std::numeric_limits<double>::max())
        throw AVMException::MemoryException("Overflow value");
    return (new Operands<double>(DOUBLE, value));
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
	std::stringstream str(value);
    double res = 0;

    str >> res;
    if (str.fail())
        throw AVMException::MemoryException("Impossible conversion");
    if (res < std::numeric_limits<long double>::min())
        throw AVMException::MemoryException("Underflow value");
    if (res > std::numeric_limits<long double>::max())
        throw AVMException::MemoryException("Overflow value");
    return (new Operands<long double>(BIGDECIMAL, value));
}
