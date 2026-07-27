#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	// A single bidirectional iterator template used to generate both
	//   iterator        = list_iterator<T, Node, T&, T*>
	//   const_iterator  = list_iterator<T, Node, const T&, const T*>
	// Only the reference/pointer types differ; the node-walking logic is shared.
	template <class T, class Node, class Ref, class Ptr>
	class list_iterator
	{
		public:
			typedef T									value_type;
			typedef Ref									reference;
			typedef Ptr									pointer;
			typedef ptrdiff_t							difference_type;
			typedef ft::bidirectional_iterator_tag		iterator_category;

		private:
			Node	*_node;

			// every instantiation is a friend of every other, so the
			// converting constructor and comparisons can read _node.
			template <class, class, class, class>
			friend class list_iterator;

			// the container may reach the node it owns
			template<class, class>
			friend class list;

		public:
			list_iterator():
				_node(NULL)
			{
			}
			list_iterator(Node *node):
				_node(node)
			{
			}
			// iterator -> const_iterator (never the reverse: const T* does
			// not convert to T*, so the wrong direction fails to compile).
			template <class R2, class P2>
			list_iterator(const list_iterator<T, Node, R2, P2>& other):
				_node(other._node)
			{
			}
			list_iterator&	operator=(const list_iterator& other)
			{
				_node = other._node;
				return (*this);
			}
			~list_iterator()
			{
			}

			reference	operator*() const
			{
				return (_node->value);
			}
			pointer		operator->() const
			{
				return (&_node->value);
			}

			list_iterator&	operator++()
			{
				_node = _node->next;
				return (*this);
			}
			list_iterator	operator++(int)
			{
				list_iterator	tmp(*this);
				_node = _node->next;
				return (tmp);
			}
			list_iterator&	operator--()
			{
				_node = _node->prev;
				return (*this);
			}
			list_iterator	operator--(int)
			{
				list_iterator	tmp(*this);
				_node = _node->prev;
				return (tmp);
			}

			template <class R2, class P2>
			bool	operator==(const list_iterator<T, Node, R2, P2>& other) const
			{
				return (_node == other._node);
			}
			template <class R2, class P2>
			bool	operator!=(const list_iterator<T, Node, R2, P2>& other) const
			{
				return (_node != other._node);
			}
	};
}

#endif
