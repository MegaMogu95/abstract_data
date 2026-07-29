#ifndef UTILITY_TPP
# define UTILITY_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  pair                                                               //
	// ------------------------------------------------------------------ //

	template<class T1, class T2>
	pair<T1, T2>::pair()
	{
	}

	template<class T1, class T2>
	pair<T1, T2>::pair(const first_type& a, const second_type& b)
	{
		(void)a;
		(void)b;
	}

	template<class T1, class T2>
	template<class U1, class U2>
	pair<T1, T2>::pair(const pair<U1, U2>& other)
	{
		(void)other;
	}

	template<class T1, class T2>
	pair<T1, T2>&	pair<T1, T2>::operator=(const pair& other)
	{
		(void)other;
		return (*this);
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T1, class T2>
	pair<T1, T2>	make_pair(T1 t, T2 u)
	{
		return (pair<T1, T2>(t, u));
	}

	template<class T1, class T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T1, class T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T1, class T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T1, class T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T1, class T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T1, class T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif
