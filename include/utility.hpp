#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  pair                                                               //
	// ------------------------------------------------------------------ //

	template<class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair();
		pair(const first_type& a, const second_type& b);
		template<class U1, class U2>
		pair(const pair<U1, U2>& other);

		pair&	operator=(const pair& other);
	};

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T1, class T2>
	pair<T1, T2>	make_pair(T1 t, T2 u);

	template<class T1, class T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs);
}

# include "utility.tpp"

#endif
