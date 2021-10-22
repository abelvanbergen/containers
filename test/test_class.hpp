/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_class.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 08:28:47 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/09/27 08:56:35 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CLASS_HPP
# define TEST_CLASS_HPP

# include <iostream>

class test
{
	private:

	public:

	int	_i;

	test&	operator=(const test& x)
	{
		std::cout << "assignment operator called" << std::endl;
		this->_i = x._i;
		return *this;
	}

	test(const test& x)
	{
		std::cout << "copy constructor called" << std::endl;
		this->_i = x._i;
	}

	test(void) : _i(0)
	{
		std::cout << "default constructor called" << std::endl;
	}

	~test(void)
	{
		std::cout << "default destructor called" << std::endl;
	}
};

#endif
