#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "deque.hpp"
# include "vector.hpp"
# include "functional.hpp" //for ft::less

namespace ft
{
	// ------------------------------------------------------------------ //
	//  queue                                                              //
	// ------------------------------------------------------------------ //

	template<class T, class Container = ft::deque<T> >
	class queue
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;

			explicit queue(const Container& cont = Container());
			~queue();
			queue&	operator=(const queue& other);

			bool		empty() const;
			size_type	size() const;
			value_type&			front();
			const value_type&	front() const;
			value_type&			back();
			const value_type&	back() const;
			void		push(const value_type& value);
			void		pop();

		protected:
			Container	c;

			// friendship is required so the relational operators can reach the
			// protected underlying container.
			template<class T1, class C1>
			friend bool	operator==(const queue<T1, C1>&, const queue<T1, C1>&);
			template<class T1, class C1>
			friend bool	operator<(const queue<T1, C1>&, const queue<T1, C1>&);
	};

	template<class T, class Container>
	bool	operator==(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs);
	template<class T, class Container>
	bool	operator!=(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs);
	template<class T, class Container>
	bool	operator<(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs);
	template<class T, class Container>
	bool	operator<=(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs);
	template<class T, class Container>
	bool	operator>(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs);
	template<class T, class Container>
	bool	operator>=(const queue<T, Container>& lhs,
		const queue<T, Container>& rhs);

	// ------------------------------------------------------------------ //
	//  priority_queue                                                     //
	// ------------------------------------------------------------------ //

	template<class T, class Container = ft::vector<T>,
		class Compare = ft::less<typename Container::value_type> >
	class priority_queue
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;

			explicit priority_queue(const Compare& compare = Compare(),
				const Container& cont = Container());
			template<class InputIt>
			priority_queue(InputIt first, InputIt last,
				const Compare& compare = Compare(),
				const Container& cont = Container());
			~priority_queue();
			priority_queue&	operator=(const priority_queue& other);

			bool				empty() const;
			size_type			size() const;
			const value_type&	top() const;
			void				push(const value_type& value);
			void				pop();

		protected:
			Container	c;
			Compare		comp;
	};
}

# include "queue.tpp"

#endif
