/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 08:53:50 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/15 18:52:54 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Nog toe te voegen:
//	-map::swap
//	-map::equal_range


#include <deque>
#include <string>
#include <iostream>
#include <exception>

#ifdef STD
	#define s std
	#include <vector>
	#include <map>
	#include <stack>
#else
	#define s ft
	#include <ft_vector.hpp>
	#include <ft_map.hpp>
	#include <ft_stack.hpp>
#endif

void	testVector();
void	testVConstructors();
void	testVResize();
void	testVReserve();
void	testVAtFrontBackPushPopClear();
void	testVSwap();
void	testVAssign();
void	testVInsert();
void	testVErase();
void	testVIterator();
void	testVMoreIterator();
void	testVIteratorOperators();
void	testVNonMemberFunctions();
void	testVstresstest();

void	testMap();
void	testMConstructorsAssignmentOperator();
void	testMCapacity();
void	testMElementAccess();
void	testMInsert();
void	testMErase();
void	testMClear();
void	testMFind();
void	testMIteratorFunctions();
void	TestMIteratorOperators();
void	testMstresstest();

void	testStack();
void	testSConstructors();
void	testS();

void	test_is_integral();

int main(void)
{
	testVector();
	testMap();
	testStack();
	test_is_integral();
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
	testVIterator();
	testVMoreIterator();
	testVIteratorOperators();
	testVNonMemberFunctions();
	testVstresstest();
}

void	testMap(void)
{
	testMConstructorsAssignmentOperator();
	testMCapacity();
	testMElementAccess();
	testMInsert();
	testMErase();
	testMClear();
	testMFind();
	testMIteratorFunctions();
	TestMIteratorOperators();
	testMstresstest();
}

void	testStack()
{
	testSConstructors();
	testS();
}

template <typename T>
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

template <typename T1, typename T2>
void	printValueType(s::pair<T1, T2> toPrint)
{
	std::cout << "first: " << toPrint.first << "	second: " << toPrint.second << std::endl;
}

template <typename T1, typename T2>
void printMap(const s::map<T1, T2> &map)
{
    std::cout << "printing map -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "size: " << map.size() << std::endl;
	typename s::map<T1,T2>::const_iterator itr = map.begin();
	for (; itr != map.end(); itr++)
	{
		printValueType(*itr);
	}
	std::cout << "---------------------------------------------" << std::endl;
	// map.printTree();
	std::cout << "---------------------------------------------" << std::endl << std::endl;
}

template <typename T>
void	printStack(s::stack<T> &stack)
{
	std::cout << "printing stack -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "size: " << stack.size() << "	top:" << stack.top() << std::endl;
}

void	testVConstructors()
{
	std::cout << "+---------------------+" << std::endl;
	std::cout << "| Vector constructors |" << std::endl;
	std::cout << "+---------------------+" << std::endl << std::endl;

	s::vector<int> one;
	s::vector<int> two(7, 10);
	s::vector<int> three(two);
	s::vector<int> four;
	s::vector<int> five;
	s::vector<int> six(1, 1);
	s::vector<int> seven(two.begin(), two.end());
	s::vector<int> eight(one.begin(), one.end());
	s::vector<int> nine(0, 10);

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
	std::cout << "+---------------+" << std::endl;
	std::cout << "| Vector resize |" << std::endl;
	std::cout << "+---------------+" << std::endl << std::endl;

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
	std::cout << "+----------------+" << std::endl;
	std::cout << "| Vector reserve |" << std::endl;
	std::cout << "+----------------+" << std::endl << std::endl;

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
	std::cout << "+------------------------------------------+" << std::endl;
	std::cout << "| Vector at, front, back, push, pop, clear |" << std::endl;
	std::cout << "+------------------------------------------+" << std::endl << std::endl;

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
	std::cout << "+-------------+" << std::endl;
	std::cout << "| Vector swap |" << std::endl;
	std::cout << "+-------------+" << std::endl << std::endl;

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
	std::cout << "+---------------+" << std::endl;
	std::cout << "| Vector assign |" << std::endl;
	std::cout << "+---------------+" << std::endl << std::endl;

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
	std::cout << "+---------------+" << std::endl;
	std::cout << "| Vector insert |" << std::endl;
	std::cout << "+---------------+" << std::endl << std::endl;

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
	std::cout << "+--------------+" << std::endl;
	std::cout << "| Vector erase |" << std::endl;
	std::cout << "+--------------+" << std::endl << std::endl;

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
	std::cout << std::endl << std::endl << std::endl;
}

void	testVIterator()
{
	std::cout << "+-----------------+" << std::endl;
	std::cout << "| Vector iterator |" << std::endl;
	std::cout << "+-----------------+" << std::endl << std::endl;

	s::vector<char> one(1, 'A');
	one.push_back('B');
	one.push_back('C');
	one.push_back('D');
	one.push_back('E');

	s::vector<char>::iterator it = one.begin();
	for (; it != one.end(); it++)
		std::cout << *it;
	std::cout << std::endl;
	it--;
	std::cout << *it << std::endl;
	s::vector<char>::iterator it2 = one.begin() + 4;
	std::cout << (it == it2) << std::endl;
	std::cout << (it != it2) << std::endl;
	s::vector<std::string> vec;
	vec.push_back("abeltje");
	vec.push_back("remcopamper");
	s::vector<std::string>::iterator it3 = vec.begin();
	std::cout << it3->append("jemoederaandepoeder") << std::endl;

	s::vector<std::string> vec2;
	vec2.push_back("abeltje");
	vec2.push_back("remcopamper");
	s::vector<std::string>::const_iterator it4 = vec2.begin();
	std::cout << *it4 << std::endl;
	std::cout << it4->data() << std::endl;
}

void	testVMoreIterator()
{
	std::cout << "+----------------------+" << std::endl;
	std::cout << "| Vector more iterator |" << std::endl;
	std::cout << "+----------------------+" << std::endl << std::endl;
	s::vector<int>							vec;
	s::vector<int>::iterator				it;
	s::vector<int>::const_iterator			cit;
	s::vector<int>::reverse_iterator		rit;
	s::vector<int>::const_reverse_iterator	crit;

	for (size_t i = 0; i < 15; i++)
		vec.push_back(i);

	it = vec.begin();
	cit = vec.begin();
	rit = vec.rbegin();
	crit = vec.rbegin();
	std::cout << "Begin: " << *it << std::endl;
	std::cout << "Const begin: " << *cit << std::endl;
	std::cout << "Reverse begin: " << *rit << std::endl;
	std::cout << "Const reverse begin: " << *crit << std::endl;
	
	it = vec.end() - 1;
	cit = vec.end() - 1;
	rit = vec.rend() - 1;
	crit = vec.rend() - 1;
	std::cout << "End: " << *it << std::endl;
	std::cout << "Const end: " << *cit << std::endl;
	std::cout << "Reverse end: " << *rit << std::endl;
	std::cout << "Const reverse end: " << *crit << std::endl;
	printVector(vec);
}

void	testVIteratorOperators()
{
	std::cout << "+---------------------------+" << std::endl;
	std::cout << "| Vector iterator operators |" << std::endl;
	std::cout << "+---------------------------+" << std::endl << std::endl;
	s::vector<std::string>							vec;
	s::vector<std::string>::iterator				it;
	s::vector<std::string>::const_iterator			cit;
	s::vector<std::string>::reverse_iterator		rit;
	s::vector<std::string>::const_reverse_iterator	crit;

	vec.push_back("I would like to express my appreciation to Ingmar and Remco.");
	vec.push_back("Besides being awesome people and friends they helped me a lot with ft_containers.");
	vec.push_back("Ingmar is a expert in iterators and every container itself.");
	vec.push_back("He explained traits like a champ and could solve all my compile errors.");
	vec.push_back("Rmeco made sure I tested all the stuff i did not want to see anymore!");
	vec.push_back("P.S. special mention to Lars for his slaps when I did something very stupid.");

	it = vec.begin();
	cit = vec.begin();
	rit = vec.rend() - 1;
	crit = vec.rend() - 1;
	// *it
	std::cout << "*it: " << *it << " | *cit: " << *cit << " | *rit: " << *rit << " | *crit: " << *crit << std::endl;	
	// it->
	std::cout << "->it: " << it->append("->op1") << " | ->cit: "<< cit->data() << " | ->rit: "<< rit->append("->op2")<< " | ->crit: " << crit->data() << std::endl;
	// ++it & --rit
	std::cout << "++it: " << *++it << " | ++cit: " << *++cit << " | --rit: " << *--rit << " | --crit: " << *--crit << std::endl;
	// it++ & rit--
	std::cout << "it++: " << *it++ << " | cit++: " << *cit++ << " | rit--: " << *rit-- << " | crit--: " << *crit-- << std::endl;
	// --it & ++rit
	std::cout << "--it: " << *--it << " | --cit: " << *--cit << " | ++rit: " << *++rit << " | ++crit: " << *++crit << std::endl;
	// it-- & rit++
	std::cout << "it--: " << *it-- << " | cit--: " << *cit-- << " | rit++: " << *rit++ << " | crit++: " << *crit++ << std::endl;
	std::cout << *it << *rit << std::endl;
	// it + n & rit - n
	it = it + 3;
	rit = rit - 3;
	std::cout << "it + n: " << *it << " | rit - n: " << *rit << std::endl;
	// n + it & n + rit
	it = 1 + it;
	rit = 1 + rit;
	std::cout << "n + it: " << *it << " | n + rit: " << *rit << std::endl;
	// it - n & rit + n
	it = it - 2;
	rit = rit + 2;
	std::cout << "it - n: " << *it << " | rit + n: " << *rit << std::endl;
	// it - cit & rit - crit
	std::cout << "it - cit: " << it - cit << " | rit - crit: " << rit - crit << std::endl;
	// it < cit
	std::cout << "it < cit: " << (it < cit) << std::endl;
	// it > cit
	std::cout << "it > cit: " << (it > cit) << std::endl;
	// it <= cit
	std::cout << "it <= cit: " << (it <= cit) << std::endl;
	// it >= cit
	std::cout << "it >= cit: " << (it >= cit) << std::endl;
	// it += n
	it += 1;
	rit -= 1;
	std::cout << "it += n: " << *it << " | rit -= n: " << *rit << std::endl;
	// it -= n
	it -= 1;
	rit += 1;
	std::cout << "it -= n: " << *it << " | rit += n: " << *rit << std::endl;
	// it[n]
	std::cout << "it[n]: " << it[2] << " | cit[n]: " << cit[2] << " | rit[n]: " << rit[-2] << " | crit[n]: " << crit[-2] << std::endl;
	printVector(vec);
}

void	testVNonMemberFunctions()
{
	std::cout << "+-----------------------------+" << std::endl;
	std::cout << "| Vector Non member functions |" << std::endl;
	std::cout << "+-----------------------------+" << std::endl << std::endl;
	s::vector<int>				vec1, vec2;
	std::string					result;
		
	for (size_t i = 0; i < 8; i++)
		vec1.push_back(i);
	std::cout << "\tRandom numbers vector (vec1) and an empty vector (vec2)" << std::endl;
	std::cout << "vec1 == vec2: " << std::boolalpha << (vec1 == vec2) << std::endl;
	std::cout << "vec1 != vec2: " << std::boolalpha << (vec1 != vec2) << std::endl;
	std::cout << "vec1 <= vec2: " << std::boolalpha << (vec1 <= vec2) << std::endl;
	std::cout << "vec1 >= vec2: " << std::boolalpha << (vec1 >= vec2) << std::endl;
	std::cout << std::endl << "\tExecuting vec2 = vec1" << std::endl;
	vec2 = vec1;
	std::cout << "vec1 == vec2: " << std::boolalpha << (vec1 == vec2) << std::endl;
	std::cout << "vec1 != vec2: " << std::boolalpha << (vec1 != vec2) << std::endl;
	std::cout << "vec1 <= vec2: " << std::boolalpha << (vec1 <= vec2) << std::endl;
	std::cout << "vec1 >= vec2: " << std::boolalpha << (vec1 >= vec2) << std::endl;
	std::cout << std::endl << "\tExecuting a push_back for vec1" << std::endl;
	vec1.push_back(1337);
	std::cout << "vec1 < vec2: " << std::boolalpha << (vec1 < vec2) << std::endl;
	std::cout << "vec1 > vec2: " << std::boolalpha << (vec1 > vec2) << std::endl;
	std::cout << std::endl << "\tChanging the first index without changing the size" << std::endl;
	vec1[0] = 1;
	vec2[0] = 2;
	std::cout << "vec1 < vec2: " << std::boolalpha << (vec1 < vec2) << std::endl;
	std::cout << "vec1 > vec2: " << std::boolalpha << (vec1 > vec2) << std::endl;
	std::cout << std::endl << "Swap:" << std::endl;
	printVector(vec1);
	printVector(vec2);
	s::swap(vec1, vec2);
	printVector(vec1);
	printVector(vec2);
}

void	testVstresstest()
{
	std::cout << "+-------------------+" << std::endl;
	std::cout << "| Vector Stress test|" << std::endl;
	std::cout << "+-------------------+" << std::endl << std::endl;
	s::vector<int>		stressVec;

	for (size_t i = 0; i < 1000000; i++)
		stressVec.insert(stressVec.begin() + i, 1, i * 3);
	printVector(stressVec);
}

void	testMConstructorsAssignmentOperator()
{
	std::cout << "+------------------+" << std::endl;
	std::cout << "| Map constructors |" << std::endl;
	std::cout << "+------------------+" << std::endl << std::endl;

	s::map<int, std::string> one;
	const s::map<int, std::string> two(one);
	s::map<int, std::string> three(one.begin(), one.end());
	s::map<int, std::string> four;
	printMap(four);
	four[1] = "This";
	printMap(four);
	four[2] = "is";
	printMap(four);
	four[3] = "a";
	printMap(four);
	four[4] = "small";
	printMap(four);
	four[5] = "test";
	printMap(four);
	four[6] = "to";
	printMap(four);
	four[7] = "test";
	printMap(four);
	four[8] = "the";
	printMap(four);
	four[9] = "constructors";
	printMap(four);
	s::map<int, std::string> five(four);
	s::map<int, std::string> six(five.begin(), five.end());
	printMap(one);
	printMap(two);
	printMap(three);
	printMap(four);
	printMap(five);
	printMap(six);
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "+-------------------------+" << std::endl;
	std::cout << "| Map assignment operator |" << std::endl;
	std::cout << "+-------------------------+" << std::endl << std::endl;

	six = one;
	printMap(one);
	printMap(six);
	one = two;
	printMap(two);
	printMap(three);
	three = four;
	four = five;
	five = six;
	printMap(one);
	printMap(two);
	printMap(three);
	printMap(four);
	printMap(five);
	printMap(six);
	std::cout << std::endl << std::endl << std::endl;
}

void	testMCapacity()
{
	std::cout << "+--------------+" << std::endl;
	std::cout << "| Map capacity |" << std::endl;
	std::cout << "+--------------+" << std::endl << std::endl;
	
	s::map<int, char> one;
	std::cout << "size: " << one.size() << "	empty: " << (one.empty() ? "True" : "False") << std::endl;
	one[10] = 'A';
	std::cout << "size: " << one.size() << "	empty: " << (one.empty() ? "True" : "False") << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

void	testMElementAccess()
{
	std::cout << "+--------------------+" << std::endl;
	std::cout << "| Map element access |" << std::endl;
	std::cout << "+--------------------+" << std::endl << std::endl;

	s::map<int, char> one;
	one[10] = 'A';
	std::cout << one.size() << one.empty() << std::endl;
	one[20] = 'B';
	std::cout << one.size() << one.empty() << std::endl;
	one[10] = 'C';
	std::cout << one.size() << one.empty() << std::endl;
	one[30] = 'D';
	std::cout << one.size() << one.empty() << std::endl;
	one[0] = 'E';
	std::cout << one.size() << one.empty() << std::endl;
	one[-10] = 'F';
	std::cout << one.size() << one.empty() << std::endl;
	one[30] = 'Z';
	std::cout << one.size() << one.empty() << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

template  <typename T1, typename T2>
void	printInsertReturn(s::pair<T1, T2> toPrint)
{
	printValueType(*(toPrint.first));
	std::cout << "new Element inserted: " << (toPrint.second ? "True" : "False") << std::endl;
}

void	testMInsert()
{
	std::cout << "+------------+" << std::endl;
	std::cout << "| Map insert |" << std::endl;
	std::cout << "+------------+" << std::endl << std::endl;
	
	s::map<int, char> one;
	s::map<int, char> two;
	s::pair<s::map<int, char>::iterator, bool> ret;
	
	ret = one.insert(s::pair<int, char>(10, 'A'));
	printInsertReturn(ret);
	printMap(one);
	ret = one.insert(s::pair<int, char>(10, 'F'));
	printInsertReturn(ret);
	printMap(one);
	ret = one.insert(s::pair<int, char>(20, 'B'));
	printInsertReturn(ret);
	for (s::map<int, char>::iterator itr = ret.first; itr != one.end(); itr++)
		printValueType(*itr);
	printMap(one);
	ret = one.insert(s::pair<int, char>(30, 'B'));
	printInsertReturn(ret);
	for (s::map<int, char>::iterator itr = ret.first; itr != one.end(); itr++)
		printValueType(*itr);
	printMap(one);
	ret = one.insert(s::pair<int, char>(40, 'B'));
	printInsertReturn(ret);
	for (s::map<int, char>::iterator itr = ret.first; itr != one.end(); itr++)
		printValueType(*itr);
	printMap(one);
	ret = one.insert(s::pair<int, char>(-20, 'B'));
	printInsertReturn(ret);
	for (s::map<int, char>::iterator itr = ret.first; itr != one.end(); itr++)
		printValueType(*itr);
	printMap(one);
	ret = one.insert(s::pair<int, char>(30, 'D'));
	printInsertReturn(ret);
	for (s::map<int, char>::iterator itr = ret.first; itr != one.end(); itr++)
		printValueType(*itr);
	printMap(one);
	std::cout << std::endl << std::endl << std::endl;
	two[110] = 'A';
	two[120] = 'B';
	two[130] = 'C';
	two[140] = 'D';
	two[150] = 'E';
	two[160] = 'F';
	printMap(two);
	two.insert(two.begin(), two.end());
	printMap(two);
	two.insert(one.begin(), one.begin());
	printMap(two);
	two.insert(one.begin(), one.begin()++);
	printMap(two);
	two.insert(one.begin(), one.end());
	printMap(two);
	std::cout << std::endl << std::endl << std::endl;
	s::map<int, char>::iterator itr;
	itr = two.insert(two.begin(), s::pair<int, char>(210, 'Z'));
	printValueType(*itr);
	printMap(two);
	itr = two.insert(two.begin(), s::pair<int, char>(220, 'P'));
	printValueType(*itr);
	printMap(two);
	itr = two.insert(two.begin(), s::pair<int, char>(0, 'O'));
	printValueType(*itr);
	printMap(two);
	itr = two.insert(two.begin(), s::pair<int, char>(-20, 'D'));
	printValueType(*itr);
	printMap(two);
	itr = two.insert(two.begin(), s::pair<int, char>(210, 'Z'));
	printValueType(*itr);
	printMap(two);
	std::cout << std::endl << std::endl << std::endl;
}

void	testMErase()
{
	std::cout << "+-----------+" << std::endl;
	std::cout << "| Map erase |" << std::endl;
	std::cout << "+-----------+" << std::endl << std::endl;
	
	s::map<int, char> one;
	one[10] = 'A';
	one[20] = 'B';
	one[30] = 'C';
	one[40] = 'D';
	one[50] = 'E';
	one[60] = 'F';
	one[70] = 'G';
	one[75] = 'H';
	one[80] = 'I';
	one[90] = 'J';
	printMap(one);
	one.erase(one.begin());
	printMap(one);
	s::map<int, char>::iterator end = one.begin();
	for (int i = 0; i < 5 ; i++)
		end++;
	one.erase(end);
	printMap(one);
	std::cout << std::endl << std::endl << "erasing 30" << std::endl;
	one.erase(30);
	printMap(one);
	one.erase(90);
	printMap(one);
	one.erase(0);
	printMap(one);
	std::cout << std::endl << std::endl << std::endl;
	one.erase(one.begin(), one.begin());
	printMap(one);
	one.erase(one.begin(), one.begin()++);
	printMap(one);
	one.erase(one.begin()++, (one.begin()++)++);
	printMap(one);
	one.erase(one.begin(), one.end());
	printMap(one);
	std::cout << std::endl << std::endl << std::endl;
}

void	testMClear(void)
{
	std::cout << "+-----------+" << std::endl;
	std::cout << "| Map clear |" << std::endl;
	std::cout << "+-----------+" << std::endl << std::endl;
	
	s::map<int, char> one;
	s::map<int, char> two;
	one[10] = 'A';
	one[20] = 'B';
	one[30] = 'C';
	one[40] = 'D';
	one[50] = 'E';
	one[60] = 'F';
	one[70] = 'G';
	one[75] = 'H';
	one[80] = 'I';
	one[90] = 'J';
	printMap(one);
	one.clear();
	printMap(one);
	printMap(two);
	two.clear();
	printMap(two);
	std::cout << std::endl << std::endl << std::endl;
}

void	testMFind()
{
	std::cout << "+-----------------+" << std::endl;
	std::cout << "| Map find, count |" << std::endl;
	std::cout << "+-----------------+" << std::endl << std::endl;
	
	s::map<int, char> one;
	s::map<int, char>::iterator ret;
	one[10] = 'A';
	one[20] = 'B';
	one[30] = 'C';
	one[40] = 'D';
	one[50] = 'E';
	one[60] = 'F';
	one[70] = 'G';
	one[75] = 'H';
	one[80] = 'I';
	one[90] = 'J';
	ret = one.find(10);
	if (ret != one.end())
		printValueType(*ret);
	ret = one.find(60);
	if (ret != one.end())
		printValueType(*ret);
	ret = one.find(90);
	if (ret != one.end())
		printValueType(*ret);
	ret = one.find(0);
	if (ret != one.end())
		printValueType(*ret);
	ret = one.find(65);
	if (ret != one.end())
		printValueType(*ret);
	ret = one.find(100);
	if (ret != one.end())
		printValueType(*ret);
	std::cout << std::endl << std::endl << std::endl;
	std::cout << one.count(10) << std::endl;
	std::cout << one.count(60) << std::endl;
	std::cout << one.count(90) << std::endl;
	std::cout << one.count(65) << std::endl;
	std::cout << one.count(10) << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	ret = one.lower_bound(9);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.upper_bound(9);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.lower_bound(10);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.upper_bound(10);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.lower_bound(11);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.upper_bound(11);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.lower_bound(72);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.upper_bound(72);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.lower_bound(90);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.upper_bound(90);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.lower_bound(100);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
	ret = one.upper_bound(100);
	for (; ret != one.end(); ret++)
		printValueType(*ret);
}

void	testMIteratorFunctions()
{
	std::cout << "+------------------------+" << std::endl;
	std::cout << "| Map Iterator functions |" << std::endl;
	std::cout << "+------------------------+" << std::endl << std::endl;
	s::map<char, int>							map;
	s::map<char, int>::iterator					it;
	s::map<char, int>::const_iterator			cit;
	s::map<char, int>::reverse_iterator			rit;
	s::map<char, int>::const_reverse_iterator	crit;

	for (size_t i = 0; i < 15; i++)
		map['a' + i] = i;
	it = map.begin();
	cit = map.begin();
	rit = map.rbegin();
	crit = map.rbegin();
	std::cout << "Begin: " << it->first << std::endl;
	std::cout << "Const begin: " << cit->first << std::endl;
	std::cout << "Reverse begin: " << rit->first << std::endl;
	std::cout << "Const reverse begin: " << crit->first << std::endl;
	
	it = --map.end()--;
	cit = --map.end()--;
	rit = --map.rend()--;
	crit = --map.rend()--;
	std::cout << "End: [" << it->first << "]" << std::endl;
	std::cout << "Const end: [" << cit->first << "]" << std::endl;
	std::cout << "Reverse end: [" << rit->first << "]" << std::endl;
	std::cout << "Const reverse end: [" << crit->first << "]" << std::endl;

	printMap(map);
}

void	TestMIteratorOperators()
{
	std::cout << "+------------------------+" << std::endl;
	std::cout << "| Map Iterator operators |" << std::endl;
	std::cout << "+------------------------+" << std::endl << std::endl;
	s::map<char, int>							map;
	s::map<char, int>::iterator				it;
	s::map<char, int>::const_iterator			cit;
	s::map<char, int>::reverse_iterator		rit;
	s::map<char, int>::const_reverse_iterator	crit;
	s::map<char, int>::iterator				itCopy(it);
	
	for (size_t i = 0; i < 15; i++)
		map['a' + i % 26] = i;
	it = map.begin();
	cit = map.begin();
	rit = --map.rend()--;
	crit = --map.rend()--;
	// *it
	std::cout << "*it|*cit|*rit|*crit: " << (*it).first << (*cit).first << (*rit).first << (*crit).first << std::endl;
	// it->
	std::cout << "it->|cit->|rit->|crit->: " << it->first << cit->first << rit->first << crit->first << std::endl;
	// ++it & --rit
	std::cout << "++it|++cit|--rit|--crit: " << (++it)->first << (++cit)->first << (--rit)->first << (--crit)->first << std::endl;
	// it++ & rit--
	std::cout << "it++|cit++|rit--|crit--: " << (it++)->first << (cit++)->first << (rit--)->first << (crit--)->first << std::endl;
	// == & != & =
	std::cout << (itCopy == it) << std::endl;
	std::cout << (itCopy != it) << std::endl;
	itCopy = it;
	std::cout << (itCopy == it) << std::endl;
	std::cout << (itCopy != it) << std::endl;
}

void	testMstresstest()
{
	std::cout << "+-----------------+" << std::endl;
	std::cout << "| Map stress test |" << std::endl;
	std::cout << "+-----------------+" << std::endl << std::endl;

	s::map<int, int>	stressMap;

	for (size_t i = 0; i < 300000; i++)
		stressMap.insert(s::make_pair(i, i*i));
}

void	testSConstructors()
{
	std::cout << "+--------------------+" << std::endl;
	std::cout << "| Stack constructors |" << std::endl;
	std::cout << "+--------------------+" << std::endl << std::endl;

	std::deque<int> mydeque (3,100);
	s::vector<int> myvector (2,200);

	s::stack<int> first;
	s::stack<int,std::deque<int> > second (mydeque);

	s::stack<int,s::vector<int> > third;
	s::stack<int,s::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

void	testS()
{
	std::cout << "+------------------------+" << std::endl;
	std::cout << "| is_integral |" << std::endl;
	std::cout << "+------------------------+" << std::endl << std::endl;
	s::stack<int> first;

	std::cout << "empty: " << first.empty() << std::endl;
	first.push(10);
	printStack(first);
	std::cout << "empty: " << first.empty() << std::endl;
	first.push(10);
	first.push(20);
	first.push(30);
	first.push(40);
	printStack(first);
	first.pop();
	printStack(first);
}

void	test_is_integral()
{
	std::cout << "+-------------+" << std::endl;
	std::cout << "| is_integral |" << std::endl;
	std::cout << "+-------------+" << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << s::is_integral<char>::value << std::endl;
	std::cout << "int: " << s::is_integral<int>::value << std::endl;
	std::cout << "float: " << s::is_integral<float>::value << std::endl;

	std::cout << "char: " << s::is_integral<const char>::value << std::endl;
	std::cout << "int: " << s::is_integral<const int>::value << std::endl;
	std::cout << "float: " << s::is_integral<const float>::value << std::endl;

	std::cout << "char: " << s::is_integral<volatile char>::value << std::endl;
	std::cout << "int: " << s::is_integral<volatile int>::value << std::endl;
	std::cout << "float: " << s::is_integral<volatile float>::value << std::endl;
}
