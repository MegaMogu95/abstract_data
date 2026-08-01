#ifndef DEQUE_ITERATOR_HPP
# define DEQUE_ITERATOR_HPP

# include <stddef.h> //for size_t and ptrdiff_t
# include "iterator.hpp"

namespace ft
{
	// A single random-access iterator template used to generate both
	//   iterator        = deque_iterator<T, ChunkSize, T&, T*>
	//   const_iterator  = deque_iterator<T, ChunkSize, const T&, const T*>
	// Only the reference/pointer types differ; the map-walking logic is shared.
	//
	// Layout (the classic block-map iterator):
	//   _node   points at the current slot in the map (a T** into the T** map)
	//   _first  == *_node            : first element of the current chunk
	//   _last   == *_node + ChunkSize : one past the last element of the chunk
	//   _cur                          : the element currently pointed at,
	//                                   always inside [_first, _last)
	// Crossing a chunk boundary means retargeting _node and recomputing
	// _first/_last with _set_node, then setting _cur inside the new chunk.
	template <class T, size_t ChunkSize, class Ref, class Ptr>
	class deque_iterator
	{
		public:
			typedef T									value_type;
			typedef Ref									reference;
			typedef Ptr									pointer;
			typedef ptrdiff_t							difference_type;
			typedef ft::random_access_iterator_tag		iterator_category;

		private:
			T		**_node;
			T		*_first;
			T		*_last;
			T		*_cur;

			// every instantiation is a friend of every other, so the
			// converting constructor, comparisons and difference can read the
			// members of the opposite (const/non-const) instantiation.
			template <class, size_t, class, class>
			friend class deque_iterator;

			// the container builds iterators directly from its map.
			template <class, class>
			friend class deque;

			// Retarget onto a new map slot and recompute the chunk bounds.
			// Does NOT set _cur (the caller decides where inside the chunk).
			// TODO:
			//   _node  = new_node;
			//   _first = *new_node;
			//   _last  = _first + ChunkSize;
			void	_set_node(T** new_node)
			{
				(void)new_node;
			}

		public:
			deque_iterator():
				_node(NULL),
				_first(NULL),
				_last(NULL),
				_cur(NULL)
			{
			}

			// Built by the container from a map slot and an element inside it.
			// TODO: _set_node(node); _cur = cur;
			deque_iterator(T** node, T* cur):
				_node(NULL),
				_first(NULL),
				_last(NULL),
				_cur(NULL)
			{
				(void)node;
				(void)cur;
			}

			// iterator -> const_iterator (never the reverse: const T* does not
			// convert to T*, so the wrong direction fails to compile).
			template <class R2, class P2>
			deque_iterator(const deque_iterator<T, ChunkSize, R2, P2>& other):
				_node(other._node),
				_first(other._first),
				_last(other._last),
				_cur(other._cur)
			{
			}

			deque_iterator&	operator=(const deque_iterator& other)
			{
				_node = other._node;
				_first = other._first;
				_last = other._last;
				_cur = other._cur;
				return (*this);
			}

			~deque_iterator()
			{
			}

			// ---------------------------------------------------------------- //
			//  Dereference                                                      //
			// ---------------------------------------------------------------- //

			// TODO: return (*_cur);
			reference	operator*() const
			{
				return (*_cur);
			}
			// TODO: return (_cur);
			pointer		operator->() const
			{
				return (_cur);
			}
			// TODO: return (*(*this + n));  (reuse operator+)
			reference	operator[](difference_type n) const
			{
				(void)n;
				return (*_cur);
			}

			// ---------------------------------------------------------------- //
			//  Increment / decrement                                            //
			// ---------------------------------------------------------------- //

			// TODO: ++_cur; if (_cur == _last) { _set_node(_node + 1); _cur = _first; }
			deque_iterator&	operator++()
			{
				return (*this);
			}
			deque_iterator	operator++(int)
			{
				deque_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}
			// TODO: if (_cur == _first) { _set_node(_node - 1); _cur = _last; } --_cur;
			deque_iterator&	operator--()
			{
				return (*this);
			}
			deque_iterator	operator--(int)
			{
				deque_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}

			// ---------------------------------------------------------------- //
			//  Random-access arithmetic                                         //
			// ---------------------------------------------------------------- //

			// The one with real work. Compute the target offset inside the
			// current chunk, then figure out how many whole chunks to jump.
			// TODO (watch out for negative offsets and integer division):
			//   difference_type offset = n + (_cur - _first);
			//   if (offset >= 0 && offset < (difference_type)ChunkSize)
			//       _cur += n;                          // stays in this chunk
			//   else
			//   {
			//       difference_type node_off = (offset > 0)
			//           ? offset / (difference_type)ChunkSize
			//           : -((-offset - 1) / (difference_type)ChunkSize) - 1;
			//       _set_node(_node + node_off);
			//       _cur = _first + (offset - node_off * (difference_type)ChunkSize);
			//   }
			deque_iterator&	operator+=(difference_type n)
			{
				(void)n;
				return (*this);
			}
			deque_iterator&	operator-=(difference_type n)
			{
				return (*this += -n);
			}
			// TODO: deque_iterator tmp(*this); tmp += n; return (tmp);
			deque_iterator	operator+(difference_type n) const
			{
				(void)n;
				return (*this);
			}
			deque_iterator	operator-(difference_type n) const
			{
				return (*this + -n);
			}

			// Distance between two iterators, counting the whole chunks in
			// between plus the partial offsets at each end.
			// TODO:
			//   return ((difference_type)ChunkSize * (_node - other._node - 1)
			//       + (_cur - _first) + (other._last - other._cur));
			template <class R2, class P2>
			difference_type	operator-(
				const deque_iterator<T, ChunkSize, R2, P2>& other) const
			{
				(void)other;
				return (0);
			}

			// ---------------------------------------------------------------- //
			//  Comparisons (const/non-const interoperable)                      //
			// ---------------------------------------------------------------- //

			template <class R2, class P2>
			bool	operator==(
				const deque_iterator<T, ChunkSize, R2, P2>& other) const
			{
				return (_cur == other._cur);
			}
			template <class R2, class P2>
			bool	operator!=(
				const deque_iterator<T, ChunkSize, R2, P2>& other) const
			{
				return (_cur != other._cur);
			}
			// Ordering follows the map first, then position within the chunk.
			// TODO: return (_node == other._node ? _cur < other._cur
			//                                    : _node < other._node);
			template <class R2, class P2>
			bool	operator<(
				const deque_iterator<T, ChunkSize, R2, P2>& other) const
			{
				(void)other;
				return (false);
			}
			template <class R2, class P2>
			bool	operator>(
				const deque_iterator<T, ChunkSize, R2, P2>& other) const
			{
				return (other < *this);
			}
			template <class R2, class P2>
			bool	operator<=(
				const deque_iterator<T, ChunkSize, R2, P2>& other) const
			{
				return (!(other < *this));
			}
			template <class R2, class P2>
			bool	operator>=(
				const deque_iterator<T, ChunkSize, R2, P2>& other) const
			{
				return (!(*this < other));
			}
	};

	// n + it, to mirror it + n.
	template <class T, size_t ChunkSize, class Ref, class Ptr>
	deque_iterator<T, ChunkSize, Ref, Ptr>	operator+(
		typename deque_iterator<T, ChunkSize, Ref, Ptr>::difference_type n,
		const deque_iterator<T, ChunkSize, Ref, Ptr>& it)
	{
		return (it + n);
	}
}

#endif
