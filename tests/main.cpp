#ifdef USE_STD
# include <list>
namespace ns = std;

#else
# include "list.hpp"
	namespace ns = ft;
#endif

#include <iostream>

template<class C>
void	print_elem(C container)
{
	typename C::const_iterator it;

	std::cout << container.size() << '\n';
	it = container.begin();
	while (it != container.end())
		std::cout << *it++ << ' ';
	std::cout << '\n';
}

template<class C>
void	rprint_elem(C container)
{
	typename C::const_reverse_iterator it;
	it = container.rbegin();
	while (it != container.rend())
		std::cout << *it++ << ' ';
	std::cout << '\n';
}

int	main()
{
	ns::list<int>	list;
	ns::list<int>	other;

	for (int i = 0; i < 5; i++)
		list.push_back(i);
	for (int i = -1; i < 6; i++)
		other.push_back(i);
	print_elem(list);
	print_elem(other);
	list.merge(other);
	print_elem(list);
	print_elem(other);
	list.remove(5);
	print_elem(list);
	list.reverse();
	print_elem(list);
	list.sort();
	print_elem(list);
}