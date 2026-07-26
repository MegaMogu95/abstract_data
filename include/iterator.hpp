#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator> //for tags
# include <stddef.h> //for ptrdiff_t

namespace ft
{
	typedef std::input_iterator_tag			input_iterator_tag;
	typedef std::output_iterator_tag		output_iterator_tag;
    typedef std::forward_iterator_tag		forward_iterator_tag;
    typedef std::bidirectional_iterator_tag	bidirectional_iterator_tag;
    typedef std::random_access_iterator_tag	random_access_iterator_tag;

	template <class Iter>
	struct iterator_traits
	{
		typedef typename Iter::value_type 			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template<class Category,\
			class T, \
			class Distance = ptrdiff_t, \
			class Pointer = T*, \
			class Reference = T&>
	struct iterator
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};
}

#endif