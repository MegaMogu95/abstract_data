#ifndef LIST_TPP
# define LIST_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  Private helpers                                                    //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename list<T, Allocator>::Node*
	list<T, Allocator>::_init_end()
	{
		Node* node = _make_node();
		node->prev = node;
		node->next = node;
		return (node);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::Node*
	list<T, Allocator>::_make_node()
	{
		Node* node = _allocator.allocate(1);
		_allocator.construct(node, Node());
		return (node);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::Node*
	list<T, Allocator>::_make_node(const T& value)
	{
		Node* node = _make_node();
		node->value = value;
		return (node);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::_destroy_node(Node* node)
	{
		_allocator.destroy(node);
		_allocator.deallocate(node, 1);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::_erase_node(Node* node)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		_destroy_node(node);
		_size--;
	}

	template<class T, class Allocator>
	template<class U>
	void	list<T, Allocator>::_swap(U& a, U& b)
	{
		U	tmp = a;

		a = b;
		b = tmp;
	}

	// ------------------------------------------------------------------ //
	//  Orthodox                                                           //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	list<T, Allocator>::list(const Allocator& allocator):
		_end(_init_end()),
		_allocator(allocator),
		_size(0)
	{
	}

	template<class T, class Allocator>
	list<T, Allocator>::list(size_type count, const T& value,
		const Allocator& allocator):
		_end(_init_end()),
		_allocator(allocator),
		_size(0)
	{
		insert(end(), count, value);
	}

	template<class T, class Allocator>
	template<class InputIt>
	list<T, Allocator>::list(InputIt first, InputIt last,
		const Allocator& allocator):
		_end(_init_end()),
		_allocator(allocator),
		_size(0)
	{
		insert(end(), first, last);
	}

	template<class T, class Allocator>
	list<T, Allocator>::list(const list& other):
		_end(_init_end()),
		_size(0)
	{
		const_iterator	it;

		it = other.begin();
		while (it != other.end())
			push_back(*it++);
	}

	template<class T, class Allocator>
	list<T, Allocator>::~list()
	{
		clear();
		_destroy_node(_end);
	}

	template<class T, class Allocator>
	list<T, Allocator>&	list<T, Allocator>::operator=(const list& other)
	{
		const_iterator	it;

		if (this != &other)
		{
			clear();
			it = other.begin();
			while (it != other.end())
				push_back(*it++);
		}
		return (*this);
	}

	// ------------------------------------------------------------------ //
	//  Element access                                                     //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	T&	list<T, Allocator>::front()
	{
		return (_end->next->value);
	}

	template<class T, class Allocator>
	const T&	list<T, Allocator>::front() const
	{
		return (_end->next->value);
	}

	template<class T, class Allocator>
	T&	list<T, Allocator>::back()
	{
		return (_end->prev->value);
	}

	template<class T, class Allocator>
	const T&	list<T, Allocator>::back() const
	{
		return (_end->prev->value);
	}

	// ------------------------------------------------------------------ //
	//  Iterators                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator	list<T, Allocator>::begin()
	{
		return (_end->next);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::const_iterator	list<T, Allocator>::begin() const
	{
		return (_end->next);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator	list<T, Allocator>::end()
	{
		return (_end);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::const_iterator	list<T, Allocator>::end() const
	{
		return (_end);
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
		Node*	new_node = _make_node(value);

		new_node->next = pos._node;
		new_node->prev = pos._node->prev;
		pos._node->prev->next = new_node;
		pos._node->prev = new_node;
		_size++;
		return (iterator(new_node));
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::insert(const_iterator pos, size_type count, const T& value)
	{
		const_iterator	first;

		if (count == 0)
			return (pos);

		first = insert(pos, value);
		while (--count)
			insert(pos, value);
		return (first);
	}

	template<class T, class Allocator>
	template<class InputIt>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last)
	{
		const_iterator	pos_first;

		if (first == last)
			return (pos);
		
		pos_first = insert(pos, *first++);
		for (InputIt it = first; it != last; it++)
			insert(pos, *it);
		return (pos_first);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::erase(iterator pos)
	{
		Node	*node = pos._node;

		pos++;
		if (node != _end)
			_erase_node(node);
		return (pos);
	}

	template<class T, class Allocator>
	typename list<T, Allocator>::iterator
	list<T, Allocator>::erase(iterator first, iterator last)
	{
		while (first != last)
			first = erase(first);
		return (last);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::push_back(const T& value)
	{
		insert(_end, value);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::pop_back()
	{
		erase(iterator(_end->prev));
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::push_front(const T& value)
	{
		insert(_end->next, value);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::pop_front()
	{
		erase(iterator(_end->next));
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::resize(size_type count)
	{
		resize(count, T());
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::resize(size_type count, const T& value)
	{
		while (_size < count)
			push_back(value);
		while (_size > count)
			pop_back();
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::swap(list& other)
	{
		_swap(_end, other._end);
		_swap(_allocator, other._allocator);
		_swap(_size, other._size);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::clear()
	{
		erase(begin(), end()); 
	}

	// ------------------------------------------------------------------ //
	//  Operations                                                         //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	void	list<T, Allocator>::merge(list& other)
	{
		merge(other, less<T>());
	}

	template<class T, class Allocator>
	template<class Compare>
	void	list<T, Allocator>::merge(list& other, Compare cmp)
	{
		const_iterator	pos = begin();
		const_iterator	first = other.begin();
		const_iterator	last;

		if (this == &other)
			return ;

		while (first != other.end())
		{
			if (pos == end())
			{
				splice(pos, other);
				return ;
			}
			if (!cmp(*first, *pos)) //pos <= first
				pos++;
			else
			{
				last = first;
				last++;
				while (last != other.end() && cmp(*last, *pos))
					last++;
				splice(pos, other, first, last);
				first = last;
			}
		}
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::splice(const_iterator pos, list& other)
	{
		splice(pos, other, other.begin(), other.end());
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::splice(const_iterator pos, list& other,
		const_iterator it)
	{
		splice(pos, other, it, other.end());
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::splice(const_iterator pos, list& other,
		const_iterator first, const_iterator last)
	{
		Node	*p = pos._node;
		Node	*f = first._node;
		Node	*l = last._node->prev;
		typename iterator_traits<const_iterator>::difference_type	d;

		if (first == last || this == &other)
			return ;

		d = distance(first, last);
		other._size -= d;
		_size += d;

		f->prev->next = last._node;
		last._node->prev = f->prev;

		p->prev->next = f;
		f->prev = p->prev;
		l->next = p;
		p->prev = l;
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::remove(const T& value)
	{
		const_iterator	it = begin();

		while (it != end())
		{
			if (*it == value)
				it = erase(it);
			else
				it++;
		}
	}

	template<class T, class Allocator>
	template<class UnaryPredicate>
	void	list<T, Allocator>::remove_if(UnaryPredicate p)
	{
		const_iterator	it = begin();

		while (it != end())
		{
			if (p(*it))
				it = erase(it);
			else
				it++;
		}
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::reverse()
	{
		Node	*node = _end->next;

		while (node != _end)
		{
			_swap(node->prev, node->next);
			node = node->prev;
		}
		_swap(node->prev, node->next);
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
		sort(less<T>());
	}

	template<class T, class Allocator>
	template<class Compare>
	void	list<T, Allocator>::sort(Compare cmp)
	{
		list<T, Allocator>	l;
		const_iterator		split;

		if (_size <= 1)
			return ;

		split = begin();
		for (size_type i = 0; i < _size / 2; i++)
			split++;
		l.splice(l.end(), *this, split, end());
		l.sort(cmp);
		sort(cmp);
		merge(l, cmp);
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	bool	operator==(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename list<T, Allocator>::const_iterator	lit = lhs.begin();
		typename list<T, Allocator>::const_iterator	rit = rhs.begin();
		while (lit != lhs.end() && *lit == *rit)
		{
			lit++;
			rit++;
		}
		if (lit == lhs.end())
			return (true);
		return (false);
	}

	template<class T, class Allocator>
	bool	operator!=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		return (!operator==(lhs, rhs));
	}

	template<class T, class Allocator>
	bool	operator<(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		typename list<T, Allocator>::const_iterator	lit = lhs.begin();
		typename list<T, Allocator>::const_iterator	rit = rhs.begin();
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

	template<class T, class Allocator>
	bool	operator<=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		return (!operator>(lhs, rhs));
	}

	template<class T, class Allocator>
	bool	operator>(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		return (operator<(rhs, lhs));
	}

	template<class T, class Allocator>
	bool	operator>=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs)
	{
		return (!operator<(lhs, rhs));
	}

	template<class T, class Allocator>
	void	swap(list<T, Allocator>& lhs, list<T, Allocator>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
