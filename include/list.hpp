#ifndef LIST_HPP
# define LIST_HPP

# include <memory> //for std::allocator
# include "iterator.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class list
	{
		struct Node
		{
			T		value;
			Node	*prev;
			Node	*next;
		};
		Node	*_node;
		public:
			class iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
			{
				Node	*_node;
				iterator(Node *node):
					_node(node)
				{
				}
				public:
					//LegacyIterator
					iterator(const iterator& other):
						_node(other._node)
					{
					}
					iterator&	operator=(const iterator& other)
					{
						_node = other._node;
						return (*this);
					}
					~iterator()
					{
					}

					//LegacyInputIterator
					T&			operator*()
					{
						return (_node->value);
					}
					const T&	operator*() const
					{
						return (_node->value);
					}
					iterator	operator++()
					{
						iterator	tmp(*this);
						_node = _node->next;
						return (tmp);
					}
					bool	operator==(const iterator& other) const
					{
						return (_node == other._node);
					}
					bool	operator!=(const iterator& other) const
					{
						return (_node != other._node);
					}

					//LegacyForwardIterator
					iterator():
						_node(NULL)
					{
					}
					iterator		operator++(int)
					{
						iterator	tmp(*this);
						_node = _node->next;
						return (tmp);
					}

					//LegacyBidirectionalIterator
					iterator&	operator--()
					{
						_node = _node->prev;
						return (*this);
					}
					iterator	operator--(int)
					{
						iterator	tmp(*this);
						_node = _node->prev;
						return (tmp);
					}
			};
	};
};

#endif