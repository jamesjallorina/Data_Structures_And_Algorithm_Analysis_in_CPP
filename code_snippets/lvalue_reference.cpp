#include <iostream>
#include <vector>

using std::vector;

vector<int> partialSum(const vector<int> &arr)
{

	vector<int> result(arr.size() );
	
	result[ 0 ] = arr[ 0 ];
	for( int i = 0; i < arr.size( ); ++i)
		result[ i ] = result[ i - 1] + arr[ i ];
	
	return result;
}

int main(int argc, char **argv)
{
	
	vector<int> arr = { 1, 2, 3, 4, 5};
	vector<int> result;
	result = partialSum(arr);
	
	for( auto &x : result)
		std::cout << x << std::endl;
	return 0;
}
