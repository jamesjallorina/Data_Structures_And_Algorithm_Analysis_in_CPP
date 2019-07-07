#include <iostream>
#include "vector_implementation.h"

int main(int argc, char **argv)
{
	Vector<int> vec;
	/* test push back */
	std::cout << "test push back " << "\n";
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	std::cout << "done push back " << "\n";
	for(int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << "\n";
	/* end */
	/* test resize, reserve, size and capacity functions */
	std::cout << "vec size before : " << vec.size() << "\n";
	std::cout << "vec capacity before : " << vec.capacity() << "\n";

	vec.resize( 50 );
	std::cout << "vec size after : " << vec.size() << "\n";

	vec.reserve( 100 );
	std::cout << "vec capacity after : " << vec.capacity() << "\n";
	/* end */

	/* test pop back */
	std::cout << "vec size before : " << vec.size() << "\n";
	std::cout << "executes vec.pop_back() " << "\n";
	vec.pop_back();
	std::cout << "vec size after : " << vec.size() << std ::endl;
	/* end */

	/* test iterator */
	vec.resize(4);
	vec.reserve(4);
	std::cout << "vector size : " << vec.size() << "\n";
	std::cout << "vector capacity : " << vec.capacity() << "\n";
	std::cout << "test vector iterator " << "\n";
	Vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << "\n";
	/* end */ 

	/* test const_iterator */
	std::cout << "test const iteator " << "\n";
	Vector<int>::const_iterator cit;
	for(cit = vec.begin(); cit != vec.end(); ++cit)
	       std::cout << *cit << "\n";	
	/* end */ 
	return 0;
}
