#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <string> //std::string is explicitly allowed by the subject

namespace ft
{
	// Mirrors the part of the standard <exception>/<stdexcept> hierarchy that
	// the containers need: at() throws out_of_range, over-large allocations
	// throw length_error, and both derive from a common exception base.

	class exception
	{
		public:
			exception() throw() {}
			virtual ~exception() throw() {}
			virtual const char*	what() const throw()
			{
				return ("ft::exception");
			}
	};

	class logic_error : public exception
	{
		private:
			std::string	_msg;

		public:
			explicit logic_error(const std::string& what_arg): _msg(what_arg) {}
			virtual ~logic_error() throw() {}
			virtual const char*	what() const throw()
			{
				return (_msg.c_str());
			}
	};

	class out_of_range : public logic_error
	{
		public:
			explicit out_of_range(const std::string& what_arg):
				logic_error(what_arg) {}
	};

	class length_error : public logic_error
	{
		public:
			explicit length_error(const std::string& what_arg):
				logic_error(what_arg) {}
	};
}

#endif
