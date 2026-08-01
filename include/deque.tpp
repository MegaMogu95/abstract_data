#ifndef DEQUE_TPP
# define DEQUE_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  Private helpers                                                    //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	template<class U>
	void	deque<T, Allocator>::_swap(U& a, U& b)
	{
		U	tmp = a;

		a = b;
		b = tmp;
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::_grow(size_type count) //count > _map_capacity
	{
		T**	new_map = _map_allocator().allocate(count);
		size_type	offset = (count - _map_capacity) / 2;

		for (size_type i = 0; i < count; i++)
			new_map[i] = NULL;
		for (size_type i = 0; i < _map_capacity; i++)
			new_map[offset + i] = _map[i];
		_map_allocator().deallocate(_map, _map_capacity);
		_map_capacity = count;
		_map = new_map;
		_front += offset * _chunk_capacity;
		_end += offset * _chunk_capacity;
	}

	// Set up an empty deque: a NULL-initialised map with a single chunk placed
	// in the middle slot, and _front == _end sitting in the middle of that
	// chunk. Centring both levels guarantees head-room to grow in either
	// direction, and keeps every grow's offset >= 1 (so push_front can never
	// underflow _front).
	template<class T, class Allocator>
	void	deque<T, Allocator>::_init()
	{
		_map_capacity = 8;
		_map = _map_allocator().allocate(_map_capacity);
		for (size_type i = 0; i < _map_capacity; i++)
			_map[i] = NULL;
		_map[_map_capacity / 2] = _allocator.allocate(_chunk_capacity);
		_front = (_map_capacity / 2) * _chunk_capacity + _chunk_capacity / 2;
		_end = _front;
	}

	// ------------------------------------------------------------------ //
	//  Orthodox                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	deque<T, Allocator>::deque(const Allocator& allocator):
		_allocator(allocator)
	{
		_init();
	}

	template<class T, class Allocator>
	deque<T, Allocator>::deque(size_type count, const T& value,
		const Allocator& allocator):
		_allocator(allocator)
	{
		_init();
		while (count)
		{
			push_back(value);
			count--;
		}
	}

	template<class T, class Allocator>
	template<class InputIt>
	deque<T, Allocator>::deque(InputIt first, InputIt last,
		const Allocator& allocator):
		_allocator(allocator)
	{
		_init();
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

	template<class T, class Allocator>
	deque<T, Allocator>::deque(const deque& other):
		_allocator(other._allocator)
	{
		_init();
		for (size_type i = 0; i < other.size(); i++)
			push_back(other[i]);
	}

	template<class T, class Allocator>
	deque<T, Allocator>::~deque()
	{
		for (size_type i = _front; i < _end; i++)
			_allocator.destroy(_map[i / _chunk_capacity] + i % _chunk_capacity);
		for (size_type i = 0; i < _map_capacity; i++)
			if (_map[i])
				_allocator.deallocate(_map[i], _chunk_capacity);
		_map_allocator().deallocate(_map, _map_capacity);
	}

	template<class T, class Allocator>
	deque<T, Allocator>&	deque<T, Allocator>::operator=(const deque& other)
	{
		if (this != &other)
		{
			clear();
			for (size_type i = 0; i < other.size(); i++)
				push_back(other[i]);
		}
		return (*this);
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::assign(size_type count, const T& value)
	{
		clear();
		for (size_type i = 0; i < count; i++)
			push_back(value);
	}

	template<class T, class Allocator>
	template<class InputIt>
	void	deque<T, Allocator>::assign(InputIt first, InputIt last)
	{
		clear();
		while (first != last)
		{
			push_back(*first);
			++first;
		}
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
		if (pos >= size())
			throw ft::out_of_range("out of range error");
		return (operator[](pos));
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::at(size_type pos) const
	{
		if (pos >= size())
			throw ft::out_of_range("out of range error");
		return (operator[](pos));
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reference
	deque<T, Allocator>::operator[](size_type pos)
	{
		size_type	sum = _front + pos;

		return (_map[sum / _chunk_capacity][sum % _chunk_capacity]);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::operator[](size_type pos) const
	{
		size_type	sum = _front + pos;

		return (_map[sum / _chunk_capacity][sum % _chunk_capacity]);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reference	deque<T, Allocator>::front()
	{
		return (_map[_front / _chunk_capacity][_front % _chunk_capacity]);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::front() const
	{
		return (_map[_front / _chunk_capacity][_front % _chunk_capacity]);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::reference	deque<T, Allocator>::back()
	{
		return (_map[(_end - 1) / _chunk_capacity][(_end - 1) % _chunk_capacity]);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::const_reference
	deque<T, Allocator>::back() const
	{
		return (_map[(_end - 1) / _chunk_capacity][(_end - 1) % _chunk_capacity]);
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
		return (_front == _end);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::size_type	deque<T, Allocator>::size() const
	{
		return (_end - _front);
	}

	template<class T, class Allocator>
	typename deque<T, Allocator>::size_type	deque<T, Allocator>::max_size() const
	{
		return (_allocator.max_size());
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::resize(size_type count, T value)
	{
		while (count > size())
			push_back(value);
		while (count < size())
			pop_back();
	}

	// ------------------------------------------------------------------ //
	//  Modifiers                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	void	deque<T, Allocator>::clear()
	{
		while (size())
			pop_back();
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
		if (_end >= _chunk_capacity * _map_capacity)
			_grow(2 * _map_capacity);
		if (_map[_end / _chunk_capacity] == NULL)
			_map[_end / _chunk_capacity] = _allocator.allocate(_chunk_capacity);
		_allocator.construct(_map[_end / _chunk_capacity] + _end % _chunk_capacity, value);
		_end++;
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::pop_back()
	{
		_allocator.destroy(_map[(_end - 1) / _chunk_capacity] + (_end - 1) % _chunk_capacity);
		_end--;
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::push_front(const T& value)
	{
		if (_front == 0)
			_grow(2 * _map_capacity);
		_front--;
		if (_map[_front / _chunk_capacity] == NULL)
			_map[_front / _chunk_capacity] = _allocator.allocate(_chunk_capacity);
		_allocator.construct(_map[_front / _chunk_capacity] + _front % _chunk_capacity, value);
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::pop_front()
	{
		_allocator.destroy(_map[_front / _chunk_capacity] + _front % _chunk_capacity);
		_front++;
	}

	template<class T, class Allocator>
	void	deque<T, Allocator>::swap(deque& other)
	{
		_swap(_map, other._map);
		_swap(_map_capacity, other._map_capacity);
		_swap(_front, other._front);
		_swap(_end, other._end);
		_swap(_allocator, other._allocator);
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Alloc>
	bool	operator==(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename deque<T, Alloc>::const_iterator	lit = lhs.begin();
		typename deque<T, Alloc>::const_iterator	rit = rhs.begin();
		while (lit != lhs.end() && *lit == *rit)
		{
			lit++;
			rit++;
		}
		if (lit == lhs.end())
			return (true);
		return (false);
	}

	template<class T, class Alloc>
	bool	operator!=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!operator==(lhs, rhs));
	}

	template<class T, class Alloc>
	bool	operator<(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		typename deque<T, Alloc>::const_iterator	lit = lhs.begin();
		typename deque<T, Alloc>::const_iterator	rit = rhs.begin();
		while (lit != lhs.end() && rit != rhs.end() && *lit == *rit)
		{
			lit++;
			rit++;
		}
		if (rit == rhs.end())
			return (false);
		if (lit == lhs.end())
			return (true);
		return (*lit < *rit);
	}

	template<class T, class Alloc>
	bool	operator<=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!operator>(lhs, rhs));
	}

	template<class T, class Alloc>
	bool	operator>(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (operator<(rhs, lhs));
	}

	template<class T, class Alloc>
	bool	operator>=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!operator<(lhs, rhs));
	}

	template<class T, class Alloc>
	void	swap(deque<T, Alloc>& lhs, deque<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
