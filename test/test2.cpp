#include <iostream>
#include <vector>
#include "test_class.hpp"

int main(void)
{
	std::vector<test> vec(8, test());

	std::cout << "+=+=+=+=+=+=+=+=+=+" << std::endl;
	vec.erase(vec.begin());
	std::cout << "+=+=+=+=+=+=+=+=+=+" << std::endl;
	// vec.erase(vec.begin(), vec.end() - 1);
	// std::cout << "+=+=+=+=+=+=+=+=+=+" << std::endl;
	// vec.insert(vec.begin() + 3, 2, test_1);
	// std::cout << vec.capacity() << std::endl;
	// std::cout << "+=+=+=+=+=+=+=+=+=+" << std::endl;
}


// void insert (iterator position, size_type n, const value_type& val);
