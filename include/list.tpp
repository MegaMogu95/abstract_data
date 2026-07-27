#ifndef LIST_TPP
# define LIST_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  Private helpers                                                    //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename list<T, Allocator>::Node*
	list<T, Allocator>::_make_node(const T& value)
	{
		Node* node = _allocator.allocate(1);
		_allocator.construct(node, Node());
		node->value = value;
		return (node);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::_destroy_node(Node* node)
	{
		_allocator.destroy(node);
		_allocator.deallocate(node, 1);
	}

	// ------------------------------------------------------------------ //
	//  Orthodox                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	list<T, Allocator>::list(const Allocator& allocator):
		_front(NULL),
		_back(NULL),
		_allocator(allocator),
		_size(0)
	{
	}

	template<class T, class Allocator>
	list<T, Allocator>::list(size_type count, const T& value,
		const Allocator& allocator):
		_front(NULL),
		_back(NULL),
		_allocator(allocator),
		_size(0)
	{
		while (count--)
			push_back(value);
	}

	template<class T, class Allocator>
	template<class InputIt>
	list<T, Allocator>::list(InputIt first, InputIt last,
		const Allocator& allocator):
		_front(NULL),
		_back(NULL),
		_allocator(allocator),
		_size(0)
	{
		(void)first;
		(void)last;
	}

	template<class T, class Allocator>
	list<T, Allocator>::list(const list& other):
		_front(NULL),
		_back(NULL),
		_size(0)
	{
		(void)other;
	}

	template<class T, class Allocator>
	list<T, Allocator>::~list()
	{
		for (size_t i = 0; i < size_type; i++)
		{
			
		}
	}

	template<class T, class Allocator>
	list<T, Allocator>&	list<T, Allocator>::operator=(const list& other)
	{
		(void)other;
		return (*this);
	}

	// ------------------------------------------------------------------ //
	//  Element access                                                     //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	T&	list<T, Allocator>::front()
	{
		return (_front->value);
	}

	template<class T, class Allocator>
	const T&	list<T, Allocator>::front() const
	{
		return (_front->value);
	}

	template<class T, class Allocator>
	T&	list<T, Allocator>::back()
	{
		return (_back->value);
	}

	template<class T, class Allocator>
	const T&	list<T, Allocator>::back() const
	{
		return (_back->value);
	}

	// ------------------------------------------------------------------ //
	//  Iterators                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator	list<T, Allocator>::begin()
	{
		return (iterator(_front));
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::const_iterator	list<T, Allocator>::begin() const
	{
		return (const_iterator(_front));
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator	list<T, Allocator>::end()
	{
		return (iterator());
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::const_iterator	list<T, Allocator>::end() const
	{
		return (const_iterator());
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::reverse_iterator	list<T, Allocator>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::const_reverse_iterator
	list<T, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::reverse_iterator	list<T, Allocator>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::const_reverse_iterator
	list<T, Allocator>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	// ------------------------------------------------------------------ //
	//  Capacity                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	bool	list<T, Allocator>::empty() const
	{
		return (_size == 0);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::size_type	list<T, Allocator>::size() const
	{
		return (_size);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::size_type	list<T, Allocator>::max_size() const
	{
		return (_allocator.max_size());
	}

	// ------------------------------------------------------------------ //
	//  Modifiers                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::insert(const_iterator pos, const T& value)
	{
		(void)pos;
		(void)value;
		return (iterator());
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::insert(const_iterator pos, size_type count, const T& value)
	{
		(void)pos;
		(void)count;
		(void)value;
		return (iterator());
	}

	template<class T, class Allocator>
	template<class InputIt>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last)
	{
		(void)pos;
		(void)first;
		(void)last;
		return (iterator());
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::erase(iterator pos)
	{
		(void)pos;
		return (iterator());
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::erase(iterator first, iterator last)
	{
		(void)first;
		(void)last;
		return (iterator());
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::push_back(const T& value)
	{
		if (_size == 0)
		{
			_back = _make_node(value);
			_back->prev = NULL;
			_front = _back;
		}
		else
		{
			_back->next = _make_node(value);
			_back->next->prev = _back;
			_back = _back->next;
		}
		_back->next = NULL;
		_size++;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::pop_back()
	{
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::push_front(const T& value)
	{
		(void)value;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::pop_front()
	{
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::resize(size_type count)
	{
		(void)count;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::resize(size_type count, const T& value)
	{
		(void)count;
		(void)value;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::swap(list& other)
	{
		(void)other;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::clear()
	{
	}

	// ------------------------------------------------------------------ //
	//  Operations                                                         //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	void	list<T, Allocator>::merge(list& other)
	{
		(void)other;
	}

	template<class T, class Allocator>
	template<class Compare>
	void	list<T, Allocator>::merge(list& other, Compare cmp)
	{
		(void)other;
		(void)cmp;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::splice(const_iterator pos, list& other)
	{
		(void)pos;
		(void)other;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::splice(const_iterator pos, list& other,
		const_iterator it)
	{
		(void)pos;
		(void)other;
		(void)it;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::splice(const_iterator pos, list& other,
		const_iterator first, const_iterator last)
	{
		(void)pos;
		(void)other;
		(void)first;
		(void)last;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::remove(const T& value)
	{
		(void)value;
	}

	template<class T, class Allocator>
	template<class UnaryPredicate>
	typename list<T, Allocator>::size_type
	list<T, Allocator>::remove_if(UnaryPredicate p)
	{
		(void)p;
		return (0);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::reverse()
	{
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::unique()
	{
	}

	template<class T, class Allocator>
	template<class BinaryPredicate>
	void	list<T, Allocator>::unique(BinaryPredicate p)
	{
		(void)p;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::sort()
	{
	}

	template<class T, class Allocator>
	template<class Compare>
	void	list<T, Allocator>::sort(Compare cmp)
	{
		(void)cmp;
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	bool	operator==(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Allocator>
	bool	operator!=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Allocator>
	bool	operator<(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Allocator>
	bool	operator<=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Allocator>
	bool	operator>(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Allocator>
	bool	operator>=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class T, class Allocator>
	void	swap(list<T, Allocator>& lhs, list<T, Allocator>& rhs)
	{
		(void)lhs;
		(void)rhs;
	}
}

#endif
