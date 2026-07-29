#ifndef MAP_TPP
# define MAP_TPP

namespace ft
{
	// ================================================================== //
	//  map                                                               //
	// ================================================================== //

	template<class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>::map(const Compare& comp,
		const Allocator& allocator)
	{
		(void)comp;
		(void)allocator;
	}

	template<class Key, class T, class Compare, class Allocator>
	template<class InputIt>
	map<Key, T, Compare, Allocator>::map(InputIt first, InputIt last,
		const Compare& comp, const Allocator& allocator)
	{
		(void)first;
		(void)last;
		(void)comp;
		(void)allocator;
	}

	template<class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>::map(const map& other)
	{
		(void)other;
	}

	template<class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>::~map()
	{
	}

	template<class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>&
	map<Key, T, Compare, Allocator>::operator=(const map& other)
	{
		(void)other;
		return (*this);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::allocator_type
	map<Key, T, Compare, Allocator>::get_allocator() const
	{
		return (allocator_type());
	}

	// ------------------------------------------------------------------ //
	//  Element access                                                     //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::mapped_type&
	map<Key, T, Compare, Allocator>::operator[](const key_type& key)
	{
		(void)key;
		return (begin()->second);
	}

	// ------------------------------------------------------------------ //
	//  Iterators                                                          //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::begin()
	{
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::begin() const
	{
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::end()
	{
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::end() const
	{
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator
	map<Key, T, Compare, Allocator>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator
	map<Key, T, Compare, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator
	map<Key, T, Compare, Allocator>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator
	map<Key, T, Compare, Allocator>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	// ------------------------------------------------------------------ //
	//  Capacity                                                           //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare, class Allocator>
	bool	map<Key, T, Compare, Allocator>::empty() const
	{
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::size() const
	{
		return (0);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::max_size() const
	{
		return (0);
	}

	// ------------------------------------------------------------------ //
	//  Modifiers                                                          //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare, class Allocator>
	void	map<Key, T, Compare, Allocator>::clear()
	{
	}

	template<class Key, class T, class Compare, class Allocator>
	ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool>
	map<Key, T, Compare, Allocator>::insert(const value_type& value)
	{
		(void)value;
		return (ft::pair<iterator, bool>());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::insert(iterator hint, const value_type& value)
	{
		(void)hint;
		(void)value;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	template<class InputIt>
	void	map<Key, T, Compare, Allocator>::insert(InputIt first, InputIt last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class T, class Compare, class Allocator>
	void	map<Key, T, Compare, Allocator>::erase(iterator pos)
	{
		(void)pos;
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::erase(const key_type& key)
	{
		(void)key;
		return (0);
	}

	template<class Key, class T, class Compare, class Allocator>
	void	map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class T, class Compare, class Allocator>
	void	map<Key, T, Compare, Allocator>::swap(map& other)
	{
		(void)other;
	}

	// ------------------------------------------------------------------ //
	//  Lookup                                                             //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::count(const key_type& key) const
	{
		(void)key;
		return (0);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::find(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::find(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	ft::pair<typename map<Key, T, Compare, Allocator>::iterator,
		typename map<Key, T, Compare, Allocator>::iterator>
	map<Key, T, Compare, Allocator>::equal_range(const key_type& key)
	{
		(void)key;
		return (ft::pair<iterator, iterator>());
	}

	template<class Key, class T, class Compare, class Allocator>
	ft::pair<typename map<Key, T, Compare, Allocator>::const_iterator,
		typename map<Key, T, Compare, Allocator>::const_iterator>
	map<Key, T, Compare, Allocator>::equal_range(const key_type& key) const
	{
		(void)key;
		return (ft::pair<const_iterator, const_iterator>());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::lower_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::lower_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::upper_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::upper_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	// ------------------------------------------------------------------ //
	//  Observers                                                          //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::key_compare
	map<Key, T, Compare, Allocator>::key_comp() const
	{
		return (key_compare());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::value_compare
	map<Key, T, Compare, Allocator>::value_comp() const
	{
		return (value_compare(key_compare()));
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc>& lhs,
		map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

	// ================================================================== //
	//  multimap                                                          //
	// ================================================================== //

	template<class Key, class T, class Compare, class Allocator>
	multimap<Key, T, Compare, Allocator>::multimap(const Compare& comp,
		const Allocator& allocator)
	{
		(void)comp;
		(void)allocator;
	}

	template<class Key, class T, class Compare, class Allocator>
	template<class InputIt>
	multimap<Key, T, Compare, Allocator>::multimap(InputIt first, InputIt last,
		const Compare& comp, const Allocator& allocator)
	{
		(void)first;
		(void)last;
		(void)comp;
		(void)allocator;
	}

	template<class Key, class T, class Compare, class Allocator>
	multimap<Key, T, Compare, Allocator>::multimap(const multimap& other)
	{
		(void)other;
	}

	template<class Key, class T, class Compare, class Allocator>
	multimap<Key, T, Compare, Allocator>::~multimap()
	{
	}

	template<class Key, class T, class Compare, class Allocator>
	multimap<Key, T, Compare, Allocator>&
	multimap<Key, T, Compare, Allocator>::operator=(const multimap& other)
	{
		(void)other;
		return (*this);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::allocator_type
	multimap<Key, T, Compare, Allocator>::get_allocator() const
	{
		return (allocator_type());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::iterator
	multimap<Key, T, Compare, Allocator>::begin()
	{
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::const_iterator
	multimap<Key, T, Compare, Allocator>::begin() const
	{
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::iterator
	multimap<Key, T, Compare, Allocator>::end()
	{
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::const_iterator
	multimap<Key, T, Compare, Allocator>::end() const
	{
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::reverse_iterator
	multimap<Key, T, Compare, Allocator>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::const_reverse_iterator
	multimap<Key, T, Compare, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::reverse_iterator
	multimap<Key, T, Compare, Allocator>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::const_reverse_iterator
	multimap<Key, T, Compare, Allocator>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	multimap<Key, T, Compare, Allocator>::empty() const
	{
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::size_type
	multimap<Key, T, Compare, Allocator>::size() const
	{
		return (0);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::size_type
	multimap<Key, T, Compare, Allocator>::max_size() const
	{
		return (0);
	}

	template<class Key, class T, class Compare, class Allocator>
	void	multimap<Key, T, Compare, Allocator>::clear()
	{
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::iterator
	multimap<Key, T, Compare, Allocator>::insert(const value_type& value)
	{
		(void)value;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::iterator
	multimap<Key, T, Compare, Allocator>::insert(iterator hint,
		const value_type& value)
	{
		(void)hint;
		(void)value;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	template<class InputIt>
	void	multimap<Key, T, Compare, Allocator>::insert(InputIt first, InputIt last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class T, class Compare, class Allocator>
	void	multimap<Key, T, Compare, Allocator>::erase(iterator pos)
	{
		(void)pos;
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::size_type
	multimap<Key, T, Compare, Allocator>::erase(const key_type& key)
	{
		(void)key;
		return (0);
	}

	template<class Key, class T, class Compare, class Allocator>
	void	multimap<Key, T, Compare, Allocator>::erase(iterator first,
		iterator last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class T, class Compare, class Allocator>
	void	multimap<Key, T, Compare, Allocator>::swap(multimap& other)
	{
		(void)other;
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::size_type
	multimap<Key, T, Compare, Allocator>::count(const key_type& key) const
	{
		(void)key;
		return (0);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::iterator
	multimap<Key, T, Compare, Allocator>::find(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::const_iterator
	multimap<Key, T, Compare, Allocator>::find(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	ft::pair<typename multimap<Key, T, Compare, Allocator>::iterator,
		typename multimap<Key, T, Compare, Allocator>::iterator>
	multimap<Key, T, Compare, Allocator>::equal_range(const key_type& key)
	{
		(void)key;
		return (ft::pair<iterator, iterator>());
	}

	template<class Key, class T, class Compare, class Allocator>
	ft::pair<typename multimap<Key, T, Compare, Allocator>::const_iterator,
		typename multimap<Key, T, Compare, Allocator>::const_iterator>
	multimap<Key, T, Compare, Allocator>::equal_range(const key_type& key) const
	{
		(void)key;
		return (ft::pair<const_iterator, const_iterator>());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::iterator
	multimap<Key, T, Compare, Allocator>::lower_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::const_iterator
	multimap<Key, T, Compare, Allocator>::lower_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::iterator
	multimap<Key, T, Compare, Allocator>::upper_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::const_iterator
	multimap<Key, T, Compare, Allocator>::upper_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::key_compare
	multimap<Key, T, Compare, Allocator>::key_comp() const
	{
		return (key_compare());
	}

	template<class Key, class T, class Compare, class Allocator>
	typename multimap<Key, T, Compare, Allocator>::value_compare
	multimap<Key, T, Compare, Allocator>::value_comp() const
	{
		return (value_compare(key_compare()));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator==(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator!=(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator<(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator<=(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator>(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool	operator>=(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class Key, class T, class Compare, class Alloc>
	void	swap(multimap<Key, T, Compare, Alloc>& lhs,
		multimap<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
