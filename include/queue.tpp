#ifndef QUEUE_TPP
# define QUEUE_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  queue                                                              //
	// ------------------------------------------------------------------ //

	template<class T, class Container>
	queue<T, Container>::queue(const Container& cont)
	{
		(void)cont;
	}

	template<class T, class Container>
	queue<T, Container>::~queue()
	{
	}

	template<class T, class Container>
	queue<T, Container>&	queue<T, Container>::operator=(const queue& other)
	{
		(void)other;
		return (*this);
	}

	template<class T, class Container>
	bool	queue<T, Container>::empty() const
	{
		return (true);
	}

	template<class T, class Container>
	typename queue<T, Container>::size_type	queue<T, Container>::size() const
	{
		return (0);
	}

	template<class T, class Container>
	typename queue<T, Container>::value_type&	queue<T, Container>::front()
	{
		return (c.front());
	}

	template<class T, class Container>
	const typename queue<T, Container>::value_type&
	queue<T, Container>::front() const
	{
		return (c.front());
	}

	template<class T, class Container>
	typename queue<T, Container>::value_type&	queue<T, Container>::back()
	{
		return (c.back());
	}

	template<class T, class Container>
	const typename queue<T, Container>::value_type&
	queue<T, Container>::back() const
	{
		return (c.back());
	}

	template<class T, class Container>
	void	queue<T, Container>::push(const value_type& value)
	{
		(void)value;
	}

	template<class T, class Container>
	void	queue<T, Container>::pop()
	{
	}

	template<class T, class Container>
	bool	operator==(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template<class T, class Container>
	bool	operator!=(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Container>
	bool	operator<(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template<class T, class Container>
	bool	operator<=(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Container>
	bool	operator>(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Container>
	bool	operator>=(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs)
	{
		return (!(lhs < rhs));
	}

	// ------------------------------------------------------------------ //
	//  priority_queue                                                     //
	// ------------------------------------------------------------------ //

	template<class T, class Container, class Compare>
	priority_queue<T, Container, Compare>::priority_queue(const Compare& compare,
		const Container& cont)
	{
		(void)compare;
		(void)cont;
	}

	template<class T, class Container, class Compare>
	template<class InputIt>
	priority_queue<T, Container, Compare>::priority_queue(InputIt first,
		InputIt last, const Compare& compare, const Container& cont)
	{
		(void)first;
		(void)last;
		(void)compare;
		(void)cont;
	}

	template<class T, class Container, class Compare>
	priority_queue<T, Container, Compare>::~priority_queue()
	{
	}

	template<class T, class Container, class Compare>
	priority_queue<T, Container, Compare>&
	priority_queue<T, Container, Compare>::operator=(const priority_queue& other)
	{
		(void)other;
		return (*this);
	}

	template<class T, class Container, class Compare>
	bool	priority_queue<T, Container, Compare>::empty() const
	{
		return (true);
	}

	template<class T, class Container, class Compare>
	typename priority_queue<T, Container, Compare>::size_type
	priority_queue<T, Container, Compare>::size() const
	{
		return (0);
	}

	template<class T, class Container, class Compare>
	const typename priority_queue<T, Container, Compare>::value_type&
	priority_queue<T, Container, Compare>::top() const
	{
		return (c.front());
	}

	template<class T, class Container, class Compare>
	void	priority_queue<T, Container, Compare>::push(const value_type& value)
	{
		(void)value;
	}

	template<class T, class Container, class Compare>
	void	priority_queue<T, Container, Compare>::pop()
	{
	}
}

#endif
