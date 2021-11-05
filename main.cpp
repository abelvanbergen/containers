/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 08:53:50 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/11/02 11:18:51 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <exception>
#include "ft_vector.hpp"

#ifdef STD
#define s std
#else
#define s ft
#endif

void	testVector();
void	testVConstructors();
void	testVIterators();
void	testVResize();
void	testVReserve();
void	testVAtFrontBackPushPopClear();
void	testVSwap();
void	testVAssign();
void	testVInsert();
void	testVErase();

void	testMap();
void	testMConstructors();

int main(void)
{
	// testVector();
	testMap();
}

void	testVector(void)
{
	testVConstructors();
	testVResize();
	testVReserve();
	testVAtFrontBackPushPopClear();
	testVSwap();
	testVAssign();
	testVInsert();
	testVErase();
}

void	testMap(void)
{
	testMConstructors();

}

void

template<typename T>
void	printVector(s::vector<T> &vec)
{
	std::cout << "printing vector -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "size: " << vec.size() << "	capacity: " << vec.capacity() << std::endl;
	std::cout << "[";
	if (vec.size() > 0)
	{
		std::cout << vec[0];
		for (size_t i = 1; i < vec.size(); i++)
			std::cout << ", " << vec[i];
	}
	else
		std::cout << " ";
	std::cout << "]" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl << std::endl;
}

void printMap(mapNode *root)
{
    if(root != NULL)
    {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void	testVConstructors()
{
	std::cout << "+--------------+" << std::endl;
	std::cout << "| constructors |" << std::endl;
	std::cout << "+--------------+" << std::endl << std::endl;

	s::vector<int> one;
	s::vector<int> two((size_t)7, 10);
	s::vector<int> three(two);
	s::vector<int> four;
	s::vector<int> five;
	s::vector<int> six((size_t)1, 1);
	s::vector<int> seven(two.begin(), two.end());
	s::vector<int> eight(one.begin(), one.end());
	s::vector<int> nine((size_t)0, 10);


	std::cout << std::endl << std::endl << std::endl;
	printVector(one);
	printVector(two);
	printVector(three);
	printVector(four);
	printVector(five);
	printVector(six);
	printVector(seven);
	printVector(eight);
	printVector(nine);


	three = one;
	one = two;
	two = six;
	four = five;
	five = six;
	seven = eight;

	std::cout << std::endl << std::endl << std::endl;
	printVector(one);
	printVector(two);
	printVector(three);
	printVector(five);
	printVector(seven);

	one.push_back(20);
	std::cout << std::endl << std::endl << std::endl;
	printVector(one);

	std::cout << "Four empty: " << four.empty() << std::endl;
	std::cout << "Five empty: " << five.empty() << std::endl;
	std::cout << "Six empty: " << six.empty() << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

void	testVResize()
{
	std::cout << "+--------+" << std::endl;
	std::cout << "| Resize |" << std::endl;
	std::cout << "+--------+" << std::endl << std::endl;

	s::vector<int> one;

	one.resize(10, 6);
	printVector(one);
	one.resize(14, 7);
	printVector(one);
	one.resize(30, 8);
	printVector(one);
	one.resize(5, 9);
	printVector(one);
	one.resize(0, 10);
	printVector(one);
	one.resize(11, 11);
	printVector(one);
	std::cout << std::endl << std::endl << std::endl;
}

void	testVReserve()
{
	std::cout << "+---------+" << std::endl;
	std::cout << "| Reserve |" << std::endl;
	std::cout << "+---------+" << std::endl << std::endl;

	s::vector<int>	one;
	s::vector<int>	two(10, (size_t)10);

	one.reserve(0);
	printVector(one);
	one.reserve(1);
	printVector(one);
	one.reserve(20);
	printVector(one);
	one.reserve(10);
	printVector(one);
	two.reserve(0);
	std::cout << std::endl << std::endl << std::endl;
	printVector(two);
	two.reserve(10);
	printVector(two);
	two.reserve(15);
	printVector(two);
	std::cout << std::endl << std::endl << std::endl;
}

void	testVAtFrontBackPushPopClear()
{
	std::cout << "+-----------------------------------+" << std::endl;
	std::cout << "| At, Front, Back, Push, Pop, Clear |" << std::endl;
	std::cout << "+-----------------------------------+" << std::endl << std::endl;

	s::vector<int>	one;
	s::vector<int>	two(1, (size_t)5);

	two.push_back(6);
	std::cout << "Front: " << two.front() << std::endl;
	std::cout << "Back: " << two.back() << std::endl;

	try {
		std::cout << one.at(0);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		std::cout << two.at(0);
		std::cout << two.at(1);
		std::cout << two.at(10);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	printVector(one);
	one.push_back(9);
	printVector(one);
	try {
		std::cout << one.at(0);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	one.pop_back();
	printVector(one);
	std::cout << std::endl << std::endl << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		one.push_back(i);
		printVector(one);
	}
	std::cout << std::endl << std::endl << std::endl;
	one.clear();
	printVector(one);
	while (!two.empty())
		two.pop_back();
	printVector(two);
	std::cout << std::endl << std::endl << std::endl;
}

void	testVSwap()
{
	std::cout << "+------+" << std::endl;
	std::cout << "| Swap |" << std::endl;
	std::cout << "+------+" << std::endl << std::endl;

	s::vector<int> one;
	s::vector<int> two(3, (size_t)4);
	s::vector<int> three(10, (size_t)11);

	one.swap(two);
	printVector(one);
	printVector(two);
	one.swap(three);
	printVector(one);
	printVector(three);
	std::cout << std::endl << std::endl << std::endl;
}

void	testVAssign()
{
	std::cout << "+--------+" << std::endl;
	std::cout << "| Assign |" << std::endl;
	std::cout << "+--------+" << std::endl << std::endl;

	s::vector<char> one(10, '-');

	one.assign(0, '-');
	printVector(one);
	one.assign(5, '-');
	printVector(one);
	one.assign(10, '-');
	printVector(one);
	one.assign(14, '-');
	printVector(one);
	one.assign(30, '-');
	printVector(one);
	one.assign(7, '-');
	printVector(one);
	std::cout << std::endl << std::endl << std::endl;

	s::vector<char> two;
	s::vector<char> three;
	s::vector<char> four(20, '-');

	two.assign(one.begin(), one.end());
	printVector(two);
	two.assign(three.begin(), three.end());
	printVector(two);
	two.assign(four.begin(), four.end());
	printVector(two);
	std::cout << std::endl << std::endl << std::endl;
}

void	testVInsert()
{
	std::cout << "+--------+" << std::endl;
	std::cout << "| Insert |" << std::endl;
	std::cout << "+--------+" << std::endl << std::endl;

	//insert with iterators
	{
		s::vector<char> one(2, '-');
		s::vector<char> two(5, '*');
		s::vector<char> three(5, '&');
		s::vector<char> four(4, '@');
		s::vector<char> five;

		printVector(one);
		s::vector<char>::iterator itr = one.insert(one.begin() + 1, '+');
		printVector(one);
		std::cout << s::distance(one.begin(), itr) << std::endl;
		one.insert(one.begin(), '+');
		printVector(one);
		one.insert(one.end(), '+');
		printVector(one);
		std::cout << std::endl << std::endl << std::endl;

		std::cout << std::endl << std::endl << std::endl;
		printVector(two);
		two.insert(two.begin(), one.begin(), one.end());
		printVector(two);
		three.insert(three.begin(), two.begin(), two.end());
		four.insert(four.end(), two.begin(), two.end());
		printVector(three);
		printVector(four);
		four.insert(four.end(), two.begin(), two.begin());
		printVector(four);
		five.insert(five.begin(), two.begin(), two.begin() + 1);
		printVector(five);
		five.insert(five.begin(), two.begin(), two.begin() + 2);
		printVector(five);
		five.insert(five.begin() + 1, two.begin(), two.begin() + 1);
		printVector(five);
		std::cout << std::endl << std::endl << std::endl;
	}
	//insert with n
	{
		s::vector<char> one(2, '-');
		s::vector<char> two(5, '*');
		s::vector<char> three(5, '&');
		s::vector<char> four(4, '@');
		s::vector<char> five;

		printVector(one);
		s::vector<char>::iterator itr = one.insert(one.begin() + 1, '+');
		printVector(one);
		std::cout << s::distance(one.begin(), itr) << std::endl;
		one.insert(one.begin(), '+');
		printVector(one);
		one.insert(one.end(), '+');
		printVector(one);
		std::cout << std::endl << std::endl << std::endl;

		std::cout << std::endl << std::endl << std::endl;
		printVector(two);
		two.insert(two.begin(), 5, '-');
		printVector(two);
		three.insert(three.begin(), 10, '[');
		four.insert(four.end(), 10, ']');
		printVector(three);
		printVector(four);
		four.insert(four.end(), 0, '_');
		printVector(four);
		five.insert(five.begin(), 1, '-');
		printVector(five);
		five.insert(five.begin(), 2, '(');
		printVector(five);
		five.insert(five.begin() + 1, 1, ';');
		printVector(five);
		std::cout << std::endl << std::endl << std::endl;
	}
}

void	testVErase()
{
	s::vector<char> one(20, '+');

	printVector(one);
	one.erase(one.begin());
	printVector(one);
	s::vector<char>::iterator itr = one.erase(one.begin() + 4);
	std::cout << s::distance(one.begin(), itr) << std::endl;
	one.erase(one.end() - 7);
	printVector(one);
	one.erase(one.end() - 1);
	printVector(one);
	one.erase(one.begin() + 2, one.begin() + 4);
	printVector(one);
	itr = one.erase(one.begin(), one.begin() + 2);
	std::cout << s::distance(one.begin(), itr) << std::endl;
	printVector(one);
	one.erase(one.begin(), one.end());
	printVector(one);
}

void	testMConstructors()
{
	s::map<int, char> one;
	s::map<int, char> two(one);
	s::map<int, char> three(one.begin(), one.end());
	s::map<int, char> four;
	four[1] = "This";
	four[2] = "is";
	four[3] = "a";
	four[4] = "small";
	four[5] = "test";
	four[6] = "to";
	four[7] = "test";
	four[8] = "the";
	four[9] = "constructors";
	s::map<int, char> five(four);
	s::map<int, char> six(five.begin(), five.end());
	printMap(one);
	printMap(two);
	printMap(three);
	printMap(four);
	printMap(five);
	printMap(six);
}