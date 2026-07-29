#ifndef SET_TPP
# define SET_TPP

namespace ft
{
	// ================================================================== //
	//  set                                                               //
	// ================================================================== //

	template<class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::set(const Compare& comp,
		const Allocator& allocator)
	{
		(void)comp;
		(void)allocator;
	}

	template<class Key, class Compare, class Allocator>
	template<class InputIt>
	set<Key, Compare, Allocator>::set(InputIt first, InputIt last,
		const Compare& comp, const Allocator& allocator)
	{
		(void)first;
		(void)last;
		(void)comp;
		(void)allocator;
	}

	template<class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::set(const set& other)
	{
		(void)other;
	}

	template<class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::~set()
	{
	}

	template<class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>&
	set<Key, Compare, Allocator>::operator=(const set& other)
	{
		(void)other;
		return (*this);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::allocator_type
	set<Key, Compare, Allocator>::get_allocator() const
	{
		return (allocator_type());
	}

	// ------------------------------------------------------------------ //
	//  Iterators                                                          //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::begin()
	{
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::begin() const
	{
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::end()
	{
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::end() const
	{
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::reverse_iterator
	set<Key, Compare, Allocator>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_reverse_iterator
	set<Key, Compare, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::reverse_iterator
	set<Key, Compare, Allocator>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_reverse_iterator
	set<Key, Compare, Allocator>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	// ------------------------------------------------------------------ //
	//  Capacity                                                           //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare, class Allocator>
	bool	set<Key, Compare, Allocator>::empty() const
	{
		return (true);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::size() const
	{
		return (0);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::max_size() const
	{
		return (0);
	}

	// ------------------------------------------------------------------ //
	//  Modifiers                                                          //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare, class Allocator>
	void	set<Key, Compare, Allocator>::clear()
	{
	}

	template<class Key, class Compare, class Allocator>
	ft::pair<typename set<Key, Compare, Allocator>::iterator, bool>
	set<Key, Compare, Allocator>::insert(const value_type& value)
	{
		(void)value;
		return (ft::pair<iterator, bool>());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::insert(iterator hint, const value_type& value)
	{
		(void)hint;
		(void)value;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	template<class InputIt>
	void	set<Key, Compare, Allocator>::insert(InputIt first, InputIt last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class Compare, class Allocator>
	void	set<Key, Compare, Allocator>::erase(iterator pos)
	{
		(void)pos;
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::erase(const key_type& key)
	{
		(void)key;
		return (0);
	}

	template<class Key, class Compare, class Allocator>
	void	set<Key, Compare, Allocator>::erase(iterator first, iterator last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class Compare, class Allocator>
	void	set<Key, Compare, Allocator>::swap(set& other)
	{
		(void)other;
	}

	// ------------------------------------------------------------------ //
	//  Lookup                                                             //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::count(const key_type& key) const
	{
		(void)key;
		return (0);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::find(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::find(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	ft::pair<typename set<Key, Compare, Allocator>::iterator,
		typename set<Key, Compare, Allocator>::iterator>
	set<Key, Compare, Allocator>::equal_range(const key_type& key)
	{
		(void)key;
		return (ft::pair<iterator, iterator>());
	}

	template<class Key, class Compare, class Allocator>
	ft::pair<typename set<Key, Compare, Allocator>::const_iterator,
		typename set<Key, Compare, Allocator>::const_iterator>
	set<Key, Compare, Allocator>::equal_range(const key_type& key) const
	{
		(void)key;
		return (ft::pair<const_iterator, const_iterator>());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::lower_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::lower_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::upper_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::upper_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	// ------------------------------------------------------------------ //
	//  Observers                                                          //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::key_compare
	set<Key, Compare, Allocator>::key_comp() const
	{
		return (key_compare());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::value_compare
	set<Key, Compare, Allocator>::value_comp() const
	{
		return (value_compare());
	}

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare, class Alloc>
	bool	operator==(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class Compare, class Alloc>
	bool	operator!=(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class Key, class Compare, class Alloc>
	bool	operator<(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class Compare, class Alloc>
	bool	operator<=(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class Key, class Compare, class Alloc>
	bool	operator>(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class Compare, class Alloc>
	bool	operator>=(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class Key, class Compare, class Alloc>
	void	swap(set<Key, Compare, Alloc>& lhs, set<Key, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

	// ================================================================== //
	//  multiset                                                          //
	// ================================================================== //

	template<class Key, class Compare, class Allocator>
	multiset<Key, Compare, Allocator>::multiset(const Compare& comp,
		const Allocator& allocator)
	{
		(void)comp;
		(void)allocator;
	}

	template<class Key, class Compare, class Allocator>
	template<class InputIt>
	multiset<Key, Compare, Allocator>::multiset(InputIt first, InputIt last,
		const Compare& comp, const Allocator& allocator)
	{
		(void)first;
		(void)last;
		(void)comp;
		(void)allocator;
	}

	template<class Key, class Compare, class Allocator>
	multiset<Key, Compare, Allocator>::multiset(const multiset& other)
	{
		(void)other;
	}

	template<class Key, class Compare, class Allocator>
	multiset<Key, Compare, Allocator>::~multiset()
	{
	}

	template<class Key, class Compare, class Allocator>
	multiset<Key, Compare, Allocator>&
	multiset<Key, Compare, Allocator>::operator=(const multiset& other)
	{
		(void)other;
		return (*this);
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::allocator_type
	multiset<Key, Compare, Allocator>::get_allocator() const
	{
		return (allocator_type());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::begin()
	{
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::begin() const
	{
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::end()
	{
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::end() const
	{
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::reverse_iterator
	multiset<Key, Compare, Allocator>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_reverse_iterator
	multiset<Key, Compare, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::reverse_iterator
	multiset<Key, Compare, Allocator>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_reverse_iterator
	multiset<Key, Compare, Allocator>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	template<class Key, class Compare, class Allocator>
	bool	multiset<Key, Compare, Allocator>::empty() const
	{
		return (true);
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::size() const
	{
		return (0);
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::max_size() const
	{
		return (0);
	}

	template<class Key, class Compare, class Allocator>
	void	multiset<Key, Compare, Allocator>::clear()
	{
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::insert(const value_type& value)
	{
		(void)value;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::insert(iterator hint,
		const value_type& value)
	{
		(void)hint;
		(void)value;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	template<class InputIt>
	void	multiset<Key, Compare, Allocator>::insert(InputIt first, InputIt last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class Compare, class Allocator>
	void	multiset<Key, Compare, Allocator>::erase(iterator pos)
	{
		(void)pos;
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::erase(const key_type& key)
	{
		(void)key;
		return (0);
	}

	template<class Key, class Compare, class Allocator>
	void	multiset<Key, Compare, Allocator>::erase(iterator first, iterator last)
	{
		(void)first;
		(void)last;
	}

	template<class Key, class Compare, class Allocator>
	void	multiset<Key, Compare, Allocator>::swap(multiset& other)
	{
		(void)other;
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::count(const key_type& key) const
	{
		(void)key;
		return (0);
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::find(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::find(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	ft::pair<typename multiset<Key, Compare, Allocator>::iterator,
		typename multiset<Key, Compare, Allocator>::iterator>
	multiset<Key, Compare, Allocator>::equal_range(const key_type& key)
	{
		(void)key;
		return (ft::pair<iterator, iterator>());
	}

	template<class Key, class Compare, class Allocator>
	ft::pair<typename multiset<Key, Compare, Allocator>::const_iterator,
		typename multiset<Key, Compare, Allocator>::const_iterator>
	multiset<Key, Compare, Allocator>::equal_range(const key_type& key) const
	{
		(void)key;
		return (ft::pair<const_iterator, const_iterator>());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::lower_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::lower_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::upper_bound(const key_type& key)
	{
		(void)key;
		return (iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::upper_bound(const key_type& key) const
	{
		(void)key;
		return (const_iterator());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::key_compare
	multiset<Key, Compare, Allocator>::key_comp() const
	{
		return (key_compare());
	}

	template<class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::value_compare
	multiset<Key, Compare, Allocator>::value_comp() const
	{
		return (value_compare());
	}

	template<class Key, class Compare, class Alloc>
	bool	operator==(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class Compare, class Alloc>
	bool	operator!=(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class Key, class Compare, class Alloc>
	bool	operator<(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		return (false);
	}

	template<class Key, class Compare, class Alloc>
	bool	operator<=(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class Key, class Compare, class Alloc>
	bool	operator>(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class Compare, class Alloc>
	bool	operator>=(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class Key, class Compare, class Alloc>
	void	swap(multiset<Key, Compare, Alloc>& lhs,
		multiset<Key, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
