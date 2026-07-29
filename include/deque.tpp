#ifndef DEQUE_TPP
# define DEQUE_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  Orthodox                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	deque<T, Allocator>::deque(const Allocator& allocator):
		_map(NULL),
		_size(0),
		_capacity(1),
		_allocator(allocator)
	{
		(void)allocator;
	}

	template<class T, class Allocator>
	deque<T, Allocator>::deque(size_type count, const T& value,
		const Allocator& allocator):
		_map(NULL),
		_size(0),
		_capacity(0),
		_allocator(allocator)
	{
		(void)count;
		(void)value;
		(void)allocator;
	}

	template<class T, class Allocator>
	template<class InputIt>
	deque<T, Allocator>::deque(InputIt first, InputIt last,
		const Allocator& allocator)
	{
		(void)first;
		(void)last;
		(void)allocator;
	}

	template<class T, class Allocator>
	deque<T, Allocator>::deque(const deque& other)
	{
		(void)other;
	}

	template<class T, class Allocator>
	deque<T, Allocator>::~deque()
	{
	}

	template<class T, class Allocator>
	deque<T, Allocator>&	deque<T, Allocator>::operator=(const deque& other)
	{
		(void)other;
		return (*this);
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::assign(size_type count, const T& value)
	{
		(void)count;
		(void)value;
	}

	template<class T, class Allocator>
	template<class InputIt>
	void	deque<T, Allocator>::assign(InputIt first, InputIt last)
	{
		(void)first;
		(void)last;
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::allocator_type
	deque<T, Allocator>::get_allocator() const
	{
		return (allocator_type());
	}

	// ------------------------------------------------------------------ //
	//  Element access                                                     //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename deque<T, Allocator>::reference	deque<T, Allocator>::at(size_type pos)
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::at(size_type pos) const
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reference
	deque<T, Allocator>::operator[](size_type pos)
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::operator[](size_type pos) const
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reference	deque<T, Allocator>::front()
	{
		return (*begin());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::front() const
	{
		return (*begin());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reference	deque<T, Allocator>::back()
	{
		return (*begin());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::back() const
	{
		return (*begin());
	}

	// ------------------------------------------------------------------ //
	//  Iterators                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename deque<T, Allocator>::iterator	deque<T, Allocator>::begin()
	{
		return (iterator());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_iterator
	deque<T, Allocator>::begin() const
	{
		return (const_iterator());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::iterator	deque<T, Allocator>::end()
	{
		return (iterator());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_iterator	deque<T, Allocator>::end() const
	{
		return (const_iterator());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reverse_iterator	deque<T, Allocator>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reverse_iterator
	deque<T, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reverse_iterator	deque<T, Allocator>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reverse_iterator
	deque<T, Allocator>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	// ------------------------------------------------------------------ //
	//  Capacity                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	bool	deque<T, Allocator>::empty() const
	{
		return (true);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::size_type	deque<T, Allocator>::size() const
	{
		return (0);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::size_type	deque<T, Allocator>::max_size() const
	{
		return (0);
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::resize(size_type count, T value)
	{
		(void)count;
		(void)value;
	}

	// ------------------------------------------------------------------ //
	//  Modifiers                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	void	deque<T, Allocator>::clear()
	{
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::iterator
	deque<T, Allocator>::insert(iterator pos, const T& value)
	{
		(void)pos;
		(void)value;
		return (iterator());
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::insert(iterator pos, size_type count,
		const T& value)
	{
		(void)pos;
		(void)count;
		(void)value;
	}

	template<class T, class Allocator>
	template<class InputIt>
	void	deque<T, Allocator>::insert(iterator pos, InputIt first, InputIt last)
	{
		(void)pos;
		(void)first;
		(void)last;
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::iterator
	deque<T, Allocator>::erase(iterator pos)
	{
		(void)pos;
		return (iterator());
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::iterator
	deque<T, Allocator>::erase(iterator first, iterator last)
	{
		(void)first;
		(void)last;
		return (iterator());
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::push_back(const T& value)
	{
		(void)value;
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::pop_back()
	{
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::push_front(const T& value)
	{
		(void)value;
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::pop_front()
	{
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::swap(deque& other)
	{
		(void)other;
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Alloc>
	bool	operator==(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Alloc>
	bool	operator!=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool	operator<(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Alloc>
	bool	operator<=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool	operator>(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool	operator>=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	void	swap(deque<T, Alloc>& lhs, deque<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
