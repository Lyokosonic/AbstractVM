/*
** EPITECH PROJECT, 2020
** Exceptions.hpp
** File description:
** Handle exceptions
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>
#include <string>

namespace AVMException
{
	class Exceptions : public std::exception {
		public:
			Exceptions(std::string const &errorMessage);
			~Exceptions();
			virtual const char *what() const throw();
		private:
			std::string _errorMessage;
	};

	class ArgumentException : public Exceptions {
		public:
			ArgumentException(std::string const &errorMessage);
			~ArgumentException();
	};

	class FileException : public Exceptions {
		public:
			FileException(std::string const &errorMessage);
			~FileException();
	};

	class SyntaxException : public Exceptions {
		public:
			SyntaxException(std::string const &errorMessage);
			~SyntaxException();
	};

	class OperandException : public Exceptions {
		public:
			OperandException(std::string const &errorMessage);
			~OperandException();
	};

	class CommandException : public Exceptions {
		public:
			CommandException(std::string const &errorMessage);
			~CommandException();
	};

	class MemoryException : public Exceptions {
		public:
			MemoryException(std::string const &errorMessage);
			~MemoryException();
	};
};

#endif /* !EXCEPTIONS_HPP_ */
