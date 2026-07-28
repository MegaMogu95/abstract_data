#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace	ft
{
	template<typename T>
	struct	less
	{
		bool	operator()(const T&a, const T&b) const
		{
			return (a < b);
		}
	};
}

#endif