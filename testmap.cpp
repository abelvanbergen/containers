/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmap.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 09:59:56 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/10/21 13:56:14 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>

#include "ft_map.hpp"

#ifdef STD
#define s std
#else
#define s ft
#endif

int main(void)
{
	s::map<int, std::string> test;

	test[10] = "hoi";
	test.insert(s::pair<int, std::string>(10, "test"));
	std::cout << test[10] << std::endl;
	// std::cout << test.find(1) << std::endl;
	// std::cout << test.insert(ft::pair<int, std::string>(10, "test")) << std::endl;
	// std::cout << "size: " << test.size() << std::endl;
	// std::cout << test.find(10) << std::endl;
	// std::cout << test.insert(ft::pair<int, std::string>(10, "test")) << std::endl;
	// std::cout << "size: " << test.size() << std::endl;
	// std::cout << test.insert(ft::pair<int, std::string>(20, "test")) << std::endl;
	// std :: cout << "-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	// std::cout << test.insert(ft::pair<int, std::string>(30, "test")) << std::endl;
	// std::cout << "size: " << test.size() << std::endl;
	// std::cout << test.find(10) << std::endl;
	// std::cout << test.test() << std::endl;
	// test[40] = "test";
	// test[50] = "test";
	// std::cout << test.test() << std::endl;
}
