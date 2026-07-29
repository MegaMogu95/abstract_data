#ifndef MAP_HPP
# define MAP_HPP

# include <memory> //for std::allocator
# include "iterator.hpp"
# include "functional.hpp" //for ft::less
# include "utility.hpp" //for ft::pair

namespace ft
{
	// ------------------------------------------------------------------ //
	//  map                                                                //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare = ft::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			// NOTE: placeholder. These must be replaced by a tree-based
			// bidirectional iterator once you design the internal search tree.
			typedef pointer										iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			// Compares two value_type by comparing their keys with key_compare.
			class value_compare
			{
				friend class map;
				protected:
					Compare	comp;
					value_compare(Compare c): comp(c) {}
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool	operator()(const value_type& lhs,
						const value_type& rhs) const
					{
						return (comp(lhs.first, rhs.first));
					}
			};

			// ------------------------------------------------------------------ //
			//  Orthodox                                                           //
			// ------------------------------------------------------------------ //

			explicit map(const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			template<class InputIt>
			map(InputIt first, InputIt last, const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			map(const map& other);

			~map();

			map&	operator=(const map& other);

			allocator_type	get_allocator() const;

			// ------------------------------------------------------------------ //
			//  Element access                                                     //
			// ------------------------------------------------------------------ //

			mapped_type&	operator[](const key_type& key);

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
			void					swap(map& other);

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

	template<class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc>& lhs,
		const map<Key, T, Compare, Alloc>& rhs);

	template<class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc>& lhs,
		map<Key, T, Compare, Alloc>& rhs);

	// ------------------------------------------------------------------ //
	//  multimap                                                           //
	// ------------------------------------------------------------------ //

	template<class Key, class T, class Compare = ft::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class multimap
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			// NOTE: placeholder, see map.
			typedef pointer										iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			class value_compare
			{
				friend class multimap;
				protected:
					Compare	comp;
					value_compare(Compare c): comp(c) {}
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool	operator()(const value_type& lhs,
						const value_type& rhs) const
					{
						return (comp(lhs.first, rhs.first));
					}
			};

			explicit multimap(const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			template<class InputIt>
			multimap(InputIt first, InputIt last, const Compare& comp = Compare(),
				const Allocator& allocator = Allocator());
			multimap(const multimap& other);

			~multimap();

			multimap&	operator=(const multimap& other);

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
			// multimap allows duplicate keys, so insert always succeeds and
			// returns a plain iterator (not pair<iterator, bool>).
			iterator	insert(const value_type& value);
			iterator	insert(iterator hint, const value_type& value);
			template<class InputIt>
			void		insert(InputIt first, InputIt last);
			void		erase(iterator pos);
			size_type	erase(const key_type& key);
			void		erase(iterator first, iterator last);
			void		swap(multimap& other);

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

	template<class Key, class T, class Compare, class Alloc>
	bool	operator==(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator!=(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator<(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator<=(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator>(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs);
	template<class Key, class T, class Compare, class Alloc>
	bool	operator>=(const multimap<Key, T, Compare, Alloc>& lhs,
		const multimap<Key, T, Compare, Alloc>& rhs);

	template<class Key, class T, class Compare, class Alloc>
	void	swap(multimap<Key, T, Compare, Alloc>& lhs,
		multimap<Key, T, Compare, Alloc>& rhs);
}

# include "map.tpp"

#endif
