#ifndef LIST_HPP
# define LIST_HPP

# include <memory> //for std::allocator
# include "iterator.hpp"
# include "list_iterator.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class list
	{
		private:
			struct Node
			{
				T		value;
				Node	*prev;
				Node	*next;
			};

			typedef typename Allocator::template rebind<Node>::other node_allocator;
			Node			*_front;
			Node			*_back;
			node_allocator	_allocator;
			std::size_t		_size;

			Node*	_make_node(const T& value);
			void	_destroy_node(Node* node);

		public:
			typedef T												value_type;
			typedef Allocator 										allocator_type;
			typedef std::size_t 									size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef ft::list_iterator<T, Node, T&, T*>				iterator;
			typedef ft::list_iterator<T, Node, const T&, const T*>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			// ------------------------------------------------------------------ //
			//  Orthodox                                                           //
			// ------------------------------------------------------------------ //

			list(const Allocator& allocator = Allocator());
			list(size_type count, const T& value = T(),
				const Allocator& allocator = Allocator());
			template<class InputIt>
			list(InputIt first, InputIt last,
				const Allocator& allocator = Allocator());
			list(const list& other);

			~list();

			list&	operator=(const list& other);

			// ------------------------------------------------------------------ //
			//  Element access                                                     //
			// ------------------------------------------------------------------ //

			T&			front();
			const T&	front() const;

			// ------------------------------------------------------------------ //
			//  Iterators                                                          //
			// ------------------------------------------------------------------ //

			iterator			begin();
			const_iterator		begin() const;
			iterator			end();
			const_iterator		end() const;
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

			iterator	insert(const_iterator pos, const T& value);
			iterator	insert(const_iterator pos, size_type count, const T& value);
			template<class InputIt>
			iterator	insert(const_iterator pos, InputIt first, InputIt last);

			iterator	erase(iterator pos);
			iterator	erase(iterator first, iterator last);

			void	push_back(const T& value);
			void	pop_back();
			void	push_front(const T& value);
			void	pop_front();

			void	resize(size_type count);
			void	resize(size_type count, const T& value);

			void	swap(list &other);

			void	clear();

			// ------------------------------------------------------------------ //
			//  Operations                                                         //
			// ------------------------------------------------------------------ //

			void	merge(list& other);
			template<class Compare>
			void	merge(list&other, Compare cmp);

			void	splice(const_iterator pos, list& other);
			void	splice(const_iterator pos, list&other, const_iterator it);
			void	splice(const_iterator pos, list &other, const_iterator first, 
				const_iterator last);

			void	remove(const T& value);
			template<class UnaryPredicate>
			size_type	remove_if(UnaryPredicate p);

			void	reverse();

			void	unique();
			template<class BinaryPredicate>
			void	unique(BinaryPredicate p);

			void	sort();
			template<class Compare>
			void	sort(Compare cmp);
	};

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	bool	operator==(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs);
	template<class T, class Allocator>
	bool	operator!=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs);
	template<class T, class Allocator>
	bool	operator<(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs);
	template<class T, class Allocator>
	bool	operator<=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs);
	template<class T, class Allocator>
	bool	operator>(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs);
	template<class T, class Allocator>
	bool	operator>=(const list<T, Allocator>& lhs,
		const list<T, Allocator>& rhs);

	template<class T, class Allocator>
	void	swap(list<T, Allocator>& lhs, list<T, Allocator>& rhs);
}

# include "list.tpp"

#endif
