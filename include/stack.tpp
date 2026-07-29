#ifndef STACK_TPP
# define STACK_TPP

namespace ft
{
	template<class T, class Container>
	stack<T, Container>::stack(const Container& cont)
	{
		(void)cont;
	}

	template<class T, class Container>
	stack<T, Container>::~stack()
	{
	}

	template<class T, class Container>
	stack<T, Container>&	stack<T, Container>::operator=(const stack& other)
	{
		(void)other;
		return (*this);
	}

	template<class T, class Container>
	bool	stack<T, Container>::empty() const
	{
		return (true);
	}

	template<class T, class Container>
	typename stack<T, Container>::size_type	stack<T, Container>::size() const
	{
		return (0);
	}

	template<class T, class Container>
	typename stack<T, Container>::value_type&	stack<T, Container>::top()
	{
		return (c.back());
	}

	template<class T, class Container>
	const typename stack<T, Container>::value_type&
	stack<T, Container>::top() const
	{
		return (c.back());
	}

	template<class T, class Container>
	void	stack<T, Container>::push(const value_type& value)
	{
		(void)value;
	}

	template<class T, class Container>
	void	stack<T, Container>::pop()
	{
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Container>
	bool	operator==(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template<class T, class Container>
	bool	operator!=(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Container>
	bool	operator<(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template<class T, class Container>
	bool	operator<=(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Container>
	bool	operator>(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Container>
	bool	operator>=(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif
