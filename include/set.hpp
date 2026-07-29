#ifndef SET_HPP
# define SET_HPP

# include <memory> //for std::allocator
# include "iterator.hpp"
# include "functional.hpp" //for ft::less
# include "utility.hpp" //for ft::pair

namespace ft
{
	// ------------------------------------------------------------------ //
	//  set                                                                //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare = ft::less<Key>,
		class Allocator = std::allocator<Key> >
	class set
	{
		public:
			typedef Key											key_type;
			typedef Key											value_type;
			typedef Compare										key_compare;
			// for set the element itself is the key, so value_compare == key_compare.
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			// NOTE: placeholder. set iterators are always constant (you cannot
			// mutate a key in place), so iterator and const_iterator are the
			// same tree-based bidirectional iterator you still have to design.
			typedef pointer										iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			// ------------------------------------------------------------------ //
			//  Orthodox                                                           //
			// ------------------------------------------------------------------ //

			explicit set(const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			template<class InputIt>
			set(InputIt first, InputIt last, const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			set(const set& other);

			~set();

			set&	operator=(const set& other);

			allocator_type	get_allocator() const;

			// ------------------------------------------------------------------ //
			//  Iterators                                                          //
			// ------------------------------------------------------------------ //

			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			// ------------------------------------------------------------------ //
			//  Capacity                                                           //
			// ------------------------------------------------------------------ //

			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;

			// ------------------------------------------------------------------ //
			//  Modifiers                                                          //
			// ------------------------------------------------------------------ //

			void					clear();
			ft::pair<iterator, bool>	insert(const value_type& value);
			iterator				insert(iterator hint, const value_type& value);
			template<class InputIt>
			void					insert(InputIt first, InputIt last);
			void					erase(iterator pos);
			size_type				erase(const key_type& key);
			void					erase(iterator first, iterator last);
			void					swap(set& other);

			// ------------------------------------------------------------------ //
			//  Lookup                                                             //
			// ------------------------------------------------------------------ //

			size_type		count(const key_type& key) const;
			iterator		find(const key_type& key);
			const_iterator	find(const key_type& key) const;
			ft::pair<iterator, iterator>				equal_range(const key_type& key);
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& key) const;
			iterator		lower_bound(const key_type& key);
			const_iterator	lower_bound(const key_type& key) const;
			iterator		upper_bound(const key_type& key);
			const_iterator	upper_bound(const key_type& key) const;

			// ------------------------------------------------------------------ //
			//  Observers                                                          //
			// ------------------------------------------------------------------ //

			key_compare		key_comp() const;
			value_compare	value_comp() const;
	};

	template<class Key, class Compare, class Alloc>
	bool	operator==(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator!=(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator<(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator<=(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator>(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator>=(const set<Key, Compare, Alloc>& lhs,
		const set<Key, Compare, Alloc>& rhs);

	template<class Key, class Compare, class Alloc>
	void	swap(set<Key, Compare, Alloc>& lhs, set<Key, Compare, Alloc>& rhs);

	// ------------------------------------------------------------------ //
	//  multiset                                                           //
	// ------------------------------------------------------------------ //

	template<class Key, class Compare = ft::less<Key>,
		class Allocator = std::allocator<Key> >
	class multiset
	{
		public:
			typedef Key											key_type;
			typedef Key											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			// NOTE: placeholder, see set.
			typedef pointer										iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			explicit multiset(const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			template<class InputIt>
			multiset(InputIt first, InputIt last, const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			multiset(const multiset& other);

			~multiset();

			multiset&	operator=(const multiset& other);

			allocator_type	get_allocator() const;

			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;

			void		clear();
			// duplicate keys allowed, so insert always succeeds -> plain iterator.
			iterator	insert(const value_type& value);
			iterator	insert(iterator hint, const value_type& value);
			template<class InputIt>
			void		insert(InputIt first, InputIt last);
			void		erase(iterator pos);
			size_type	erase(const key_type& key);
			void		erase(iterator first, iterator last);
			void		swap(multiset& other);

			size_type		count(const key_type& key) const;
			iterator		find(const key_type& key);
			const_iterator	find(const key_type& key) const;
			ft::pair<iterator, iterator>				equal_range(const key_type& key);
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& key) const;
			iterator		lower_bound(const key_type& key);
			const_iterator	lower_bound(const key_type& key) const;
			iterator		upper_bound(const key_type& key);
			const_iterator	upper_bound(const key_type& key) const;

			key_compare		key_comp() const;
			value_compare	value_comp() const;
	};

	template<class Key, class Compare, class Alloc>
	bool	operator==(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator!=(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator<(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator<=(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator>(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs);
	template<class Key, class Compare, class Alloc>
	bool	operator>=(const multiset<Key, Compare, Alloc>& lhs,
		const multiset<Key, Compare, Alloc>& rhs);

	template<class Key, class Compare, class Alloc>
	void	swap(multiset<Key, Compare, Alloc>& lhs,
		multiset<Key, Compare, Alloc>& rhs);
}

# include "set.tpp"

#endif
