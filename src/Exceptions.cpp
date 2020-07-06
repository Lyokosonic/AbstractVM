/*
** EPITECH PROJECT, 2020
** Exceptions.cpp
** File description:
** Handle exceptions
*/

#include "../include/Exceptions.hpp"

AVMException::Exceptions::Exceptions(std::string const &errorMessage) : _errorMessage(errorMessage)
{
}

AVMException::Exceptions::~Exceptions()
{
}

const char *AVMException::Exceptions::what() const throw()
{
	return _errorMessage.c_str();
}

AVMException::ArgumentException::ArgumentException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

AVMException::ArgumentException::~ArgumentException()
{
}

AVMException::FileException::FileException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

AVMException::FileException::~FileException()
{
}

AVMException::SyntaxException::SyntaxException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

AVMException::SyntaxException::~SyntaxException()
{
}

AVMException::OperandException::OperandException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

AVMException::OperandException::~OperandException()
{
}

AVMException::CommandException::CommandException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

AVMException::CommandException::~CommandException()
{
}

AVMException::MemoryException::MemoryException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

AVMException::MemoryException::~MemoryException()
{
}
