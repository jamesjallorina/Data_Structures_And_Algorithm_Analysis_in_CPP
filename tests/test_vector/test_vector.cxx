#include <iostream>
#include "../../sources/vector_implementation/vector_implementation.hpp"

int main(int argc, char **argv)
{
	experimental::vector<int> vec;
	/* test push back */
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	for(int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << std::endl;
	/* end */
	/* test resize, reserve, size and capacity functions */
	std::cout << "vec size before : " << vec.size() << std::endl;
	std::cout << "vec capacity before : " << vec.capacity() << std::endl;

	vec.resize( 50 );
	std::cout << "vec size after : " << vec.size() << std::endl;

	vec.reserve( 100 );
	std::cout << "vec capacity after : " << vec.capacity() << std::endl;
	/* end */

	/* test pop back */
	std::cout << "vec size before : " << vec.size() << std::endl;
	std::cout << "executes vec.pop_back() " << std::endl;
	vec.pop_back();
	std::cout << "vec size after : " << vec.size() << std ::endl;
	/* end */

	/* test iterator */
	vec.resize(4);
	vec.reserve(4);
	std::cout << "vector size : " << vec.size() << std::endl;
	std::cout << "vector capacity : " << vec.capacity() << std::endl;
	std::cout << "test vector iterator " << std::endl;
	experimental::vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	/* end */ 

	/* test const_iterator */
	std::cout << "test const iteator " << std::endl;
	experimental::vector<int>::const_iterator cit;
	for(cit = vec.begin(); cit != vec.end(); ++cit)
	       std::cout << *cit << std::endl;	
	/* end */ 
	return 0;
}
