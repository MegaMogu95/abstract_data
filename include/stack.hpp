#ifndef STACK_HPP
# define STACK_HPP

# include "deque.hpp"

namespace ft
{
	template<class T, class Container = ft::deque<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;

			explicit stack(const Container& cont = Container());
			~stack();
			stack&	operator=(const stack& other);

			bool		empty() const;
			size_type	size() const;
			value_type&			top();
			const value_type&	top() const;
			void		push(const value_type& value);
			void		pop();

		protected:
			// The underlying container; protected because the standard exposes
			// it as such so derived adaptors and the relational operators can
			// reach it.
			Container	c;

			// friendship is required so the non-member relational operators can
			// compare the protected underlying containers.
			template<class T1, class C1>
			friend bool	operator==(const stack<T1, C1>&, const stack<T1, C1>&);
			template<class T1, class C1>
			friend bool	operator<(const stack<T1, C1>&, const stack<T1, C1>&);
	};

	// ------------------------------------------------------------------ //
	//  Non-member functions                                               //
	// ------------------------------------------------------------------ //

	template<class T, class Container>
	bool	operator==(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs);
	template<class T, class Container>
	bool	operator!=(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs);
	template<class T, class Container>
	bool	operator<(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs);
	template<class T, class Container>
	bool	operator<=(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs);
	template<class T, class Container>
	bool	operator>(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs);
	template<class T, class Container>
	bool	operator>=(const stack<T, Container>& lhs,
		const stack<T, Container>& rhs);
}

# include "stack.tpp"

#endif
