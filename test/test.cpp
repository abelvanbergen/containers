/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 13:44:02 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/09/22 16:53:15 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "ft_vector.hpp"
using namespace ft;

int main ()
{
	vector<int> second;
	vector<int> third(4, 100);

	for (int i = 0; i < 5; i++)
		second.push_back(i);
	second.push_back(108);
	second.push_back(420);
	second.push_back(69);
	second.push_back(1337);
	second.push_back(42069);
	second.push_back(789);
	for (size_t i = 0; i < second.size(); i++)
		std::cout << second.at(i) << std::endl;
	for (size_t i = 0; i < third.size(); i++)
		std::cout << third.at(i) << std::endl;
	for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	// std::cout << std::endl;
	// vector<int>::iterator it = second.begin();
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// return 0;
}
