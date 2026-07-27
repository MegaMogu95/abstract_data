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
	ns::list<int>			list;
	ns::list<int>::iterator it;

	for (int i = 0; i < 10; i++)
		list.push_back(i);
	std::cout << "list size: " << list.size() << '\n';
	print_elem(list);
	list.push_front(10);
	print_elem(list);
	list.pop_front();
	list.pop_back();
	print_elem(list);
	list.clear();
	std::cout << "list size: " << list.size() << '\n';
	print_elem(list);

	int				array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ns::list<int>	other_list(array, array + 10);
	list = other_list;
	rprint_elem(list);
	rprint_elem(other_list);
}