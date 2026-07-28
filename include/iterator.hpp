#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator> //for tags
# include <stddef.h> //for ptrdiff_t
# include "functional.hpp" //for ft::less<>

namespace ft
{
	typedef std::input_iterator_tag			input_iterator_tag;
	typedef std::output_iterator_tag		output_iterator_tag;
	typedef std::forward_iterator_tag		forward_iterator_tag;
	typedef std::bidirectional_iterator_tag	bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag	random_access_iterator_tag;

	// ---------------------------------------------------------------- //
	//  iterator_traits                                                  //
	// ---------------------------------------------------------------- //

	template <class Iter>
	struct iterator_traits
	{
		typedef typename Iter::value_type 			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	// ---------------------------------------------------------------- //
	//  iterator (base convenience class)                                //
	// ---------------------------------------------------------------- //

	template<class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&>
	struct iterator
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	// ---------------------------------------------------------------- //
	//  reverse_iterator                                                 //
	// ---------------------------------------------------------------- //

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator											iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category
																		iterator_category;
			typedef typename iterator_traits<Iterator>::value_type		value_type;
			typedef typename iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename iterator_traits<Iterator>::pointer			pointer;
			typedef typename iterator_traits<Iterator>::reference		reference;

		protected:
			Iterator	current;

		public:
			reverse_iterator():
				current()
			{
			}
			explicit reverse_iterator(iterator_type it):
				current(it)
			{
			}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& other):
				current(other.base())
			{
			}

			iterator_type	base() const
			{
				return (current);
			}

			reference	operator*() const
			{
				Iterator	tmp = current;
				return (*--tmp);
			}
			pointer		operator->() const
			{
				return (&(operator*()));
			}
			reference	operator[](difference_type n) const
			{
				return (*(*this + n));
			}

			reverse_iterator&	operator++()
			{
				--current;
				return (*this);
			}
			reverse_iterator	operator++(int)
			{
				reverse_iterator	tmp = *this;
				--current;
				return (tmp);
			}
			reverse_iterator&	operator--()
			{
				++current;
				return (*this);
			}
			reverse_iterator	operator--(int)
			{
				reverse_iterator	tmp = *this;
				++current;
				return (tmp);
			}

			reverse_iterator	operator+(difference_type n) const
			{
				return (reverse_iterator(current - n));
			}
			reverse_iterator&	operator+=(difference_type n)
			{
				current -= n;
				return (*this);
			}
			reverse_iterator	operator-(difference_type n) const
			{
				return (reverse_iterator(current + n));
			}
			reverse_iterator&	operator-=(difference_type n)
			{
				current += n;
				return (*this);
			}
	};

	template <class It1, class It2>
	bool	operator==(const reverse_iterator<It1>& lhs,
		const reverse_iterator<It2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class It1, class It2>
	bool	operator!=(const reverse_iterator<It1>& lhs,
		const reverse_iterator<It2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class It1, class It2>
	bool	operator<(const reverse_iterator<It1>& lhs,
		const reverse_iterator<It2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class It1, class It2>
	bool	operator<=(const reverse_iterator<It1>& lhs,
		const reverse_iterator<It2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class It1, class It2>
	bool	operator>(const reverse_iterator<It1>& lhs,
		const reverse_iterator<It2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class It1, class It2>
	bool	operator>=(const reverse_iterator<It1>& lhs,
		const reverse_iterator<It2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev)
	{
		return (rev + n);
	}
	template <class It1, class It2>
	typename reverse_iterator<It1>::difference_type	operator-(
		const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template<class InputIt>
	typename iterator_traits<InputIt>::difference_type
		distance(InputIt first, InputIt last)
	{
		typename iterator_traits<InputIt>::difference_type	d = 0;

		while (first++ != last)
			d++;
		return (d);
	}
}

#endif
