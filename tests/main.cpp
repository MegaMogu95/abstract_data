#ifdef USE_STD
# include <list>
namespace ns = std;

#else
# include "list.hpp"
	namespace ns = ft;
#endif

int	main()
{
	ns::list<int>::iterator it;
}