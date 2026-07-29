#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  Orthodox                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	vector<T, Allocator>::vector(const Allocator& allocator)
	{
		(void)allocator;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector(size_type count, const T& value,
		const Allocator& allocator)
	{
		(void)count;
		(void)value;
		(void)allocator;
	}

	template<class T, class Allocator>
	template<class InputIt>
	vector<T, Allocator>::vector(InputIt first, InputIt last,
		const Allocator& allocator)
	{
		(void)first;
		(void)last;
		(void)allocator;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector(const vector& other)
	{
		(void)other;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::~vector()
	{
	}

	template<class T, class Allocator>
	vector<T, Allocator>&	vector<T, Allocator>::operator=(const vector& other)
	{
		(void)other;
		return (*this);
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::assign(size_type count, const T& value)
	{
		(void)count;
		(void)value;
	}

	template<class T, class Allocator>
	template<class InputIt>
	void	vector<T, Allocator>::assign(InputIt first, InputIt last)
	{
		(void)first;
		(void)last;
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::allocator_type
	vector<T, Allocator>::get_allocator() const
	{
		return (allocator_type());
	}

	// ------------------------------------------------------------------ //
	//  Element access                                                     //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference
	vector<T, Allocator>::at(size_type pos)
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::at(size_type pos) const
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference
	vector<T, Allocator>::operator[](size_type pos)
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::operator[](size_type pos) const
	{
		(void)pos;
		return (*begin());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference	vector<T, Allocator>::front()
	{
		return (*begin());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::front() const
	{
		return (*begin());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference	vector<T, Allocator>::back()
	{
		return (*begin());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::back() const
	{
		return (*begin());
	}

	// ------------------------------------------------------------------ //
	//  Iterators                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::begin()
	{
		return (iterator());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_iterator
	vector<T, Allocator>::begin() const
	{
		return (const_iterator());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::end()
	{
		return (iterator());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_iterator
	vector<T, Allocator>::end() const
	{
		return (const_iterator());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator
	vector<T, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator
	vector<T, Allocator>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	// ------------------------------------------------------------------ //
	//  Capacity                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	bool	vector<T, Allocator>::empty() const
	{
		return (true);
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::size() const
	{
		return (0);
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type
	vector<T, Allocator>::max_size() const
	{
		return (0);
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::reserve(size_type new_cap)
	{
		(void)new_cap;
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type
	vector<T, Allocator>::capacity() const
	{
		return (0);
	}

	// ------------------------------------------------------------------ //
	//  Modifiers                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	void	vector<T, Allocator>::clear()
	{
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::insert(iterator pos, const T& value)
	{
		(void)pos;
		(void)value;
		return (iterator());
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::insert(iterator pos, size_type count,
		const T& value)
	{
		(void)pos;
		(void)count;
		(void)value;
	}

	template<class T, class Allocator>
	template<class InputIt>
	void	vector<T, Allocator>::insert(iterator pos, InputIt first, InputIt last)
	{
		(void)pos;
		(void)first;
		(void)last;
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::erase(iterator pos)
	{
		(void)pos;
		return (iterator());
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::erase(iterator first, iterator last)
	{
		(void)first;
		(void)last;
		return (iterator());
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::push_back(const T& value)
	{
		(void)value;
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::pop_back()
	{
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::resize(size_type count, T value)
	{
		(void)count;
		(void)value;
	}

	template<class T, class Allocator>
	void	vector<T, Allocator>::swap(vector& other)
	{
		(void)other;
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Alloc>
	bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	void	swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
