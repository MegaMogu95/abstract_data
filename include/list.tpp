#ifndef LIST_TPP
# define LIST_TPP

namespace ft
{
	// ------------------------------------------------------------------ //
	//  Private helpers                                                    //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	typename list<T, Allocator>::Node*
	list<T, Allocator>::_make_node(const T& value)
	{
		Node* node = _allocator.allocate(1);
		_allocator.construct(node, Node());
		node->value = value;
		return (node);
	}

	template<class T, class Allocator>
	void	list<T, Allocator>::_destroy_node(Node* node)
	{
		_allocator.destroy(node);
		_allocator.deallocate(node, 1);
	}

	// ------------------------------------------------------------------ //
	//  Constructors                                                       //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	list<T, Allocator>::list(const Allocator& allocator):
		_head(NULL),
		_allocator(allocator)
	{
	}

	template<class T, class Allocator>
	list<T, Allocator>::list(size_type count, const T& value,
		const Allocator& allocator):
		_head(NULL),
		_allocator(allocator)
	{
	}

	template<class T, class Allocator>
	template<class InputIt>
	list<T, Allocator>::list(InputIt first, InputIt last,
		const Allocator& allocator):
		_head(NULL),
		_allocator(allocator)
	{
		while (first != last)
			push_back(*first++);
	}

	template<class T, class Allocator>
	list<T, Allocator>::list(const list& other)
	{
		
	}

	// ------------------------------------------------------------------ //
	//  Modifiers                                                          //
	// ------------------------------------------------------------------ //

	template<class T, class Allocator>
	void	list<T, Allocator>::push_back(const T& value)
	{
		_head->next = _make_node(value);
		_head->next->prev = _head;
		_head = next;
		_head->next = NULL;
	}
}

#endif
