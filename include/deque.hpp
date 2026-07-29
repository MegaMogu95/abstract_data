#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <memory> //for std::allocator
# include <stddef.h> //for size_t
# include "iterator.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class deque
	{
		private:
			T**					_map;
			size_t				_size;
			size_t				_capacity;
			static const size_t	_chunk_size = 256;
			Allocator			_allocator;
		public:
			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			// NOTE: a deque is NOT contiguous, so these pointer typedefs are
			// only placeholders. They must be replaced by a custom
			// random-access iterator that walks the block-map once you design
			// the internal representation.
			typedef pointer											iterator;
			typedef const_pointer									const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			// ------------------------------------------------------------------ //
			//  Orthodox                                                           //
			// ------------------------------------------------------------------ //

			explicit deque(const Allocator& allocator = Allocator());
			explicit deque(size_type count, const T& value = T(),
				const Allocator& allocator = Allocator());
			template<class InputIt>
			deque(InputIt first, InputIt last,
				const Allocator& allocator = Allocator());
			deque(const deque& other);

			~deque();

			deque&	operator=(const deque& other);

			void	assign(size_type count, const T& value);
			template<class InputIt>
			void	assign(InputIt first, InputIt last);

			allocator_type	get_allocator() const;

			// ------------------------------------------------------------------ //
			//  Element access                                                     //
			// ------------------------------------------------------------------ //

			reference		at(size_type pos);
			const_reference	at(size_type pos) const;
			reference		operator[](size_type pos);
			const_reference	operator[](size_type pos) const;
			reference		front();
			const_reference	front() const;
			reference		back();
			const_reference	back() const;

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
			void		resize(size_type count, T value = T());

			// ------------------------------------------------------------------ //
			//  Modifiers                                                          //
			// ------------------------------------------------------------------ //

			void		clear();
			iterator	insert(iterator pos, const T& value);
			void		insert(iterator pos, size_type count, const T& value);
			template<class InputIt>
			void		insert(iterator pos, InputIt first, InputIt last);
			iterator	erase(iterator pos);
			iterator	erase(iterator first, iterator last);
			void		push_back(const T& value);
			void		pop_back();
			void		push_front(const T& value);
			void		pop_front();
			void		swap(deque& other);
	};

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Alloc>
	bool	operator==(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template<class T, class Alloc>
	bool	operator!=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template<class T, class Alloc>
	bool	operator<(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template<class T, class Alloc>
	bool	operator<=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template<class T, class Alloc>
	bool	operator>(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template<class T, class Alloc>
	bool	operator>=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);

	template<class T, class Alloc>
	void	swap(deque<T, Alloc>& lhs, deque<T, Alloc>& rhs);
}

# include "deque.tpp"

#endif
