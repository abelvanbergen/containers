/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_random_access_iterator.hpp                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 09:22:52 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/11/08 15:31:20 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# define FT_RANDOM_ACCESS_ITERATOR_HPP

# define itr ft::iterator<T, Distance, Pointer, Reference>

# include "type_traits.hpp"

namespace ft {
	template <class T, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
	class random_access_iterator
	{
		public:
			typedef T														value_type;
			typedef Distance  												difference_type;
			typedef Pointer													pointer;
			typedef Reference												reference;
			typedef random_access_iterator_tag								iterator_category;

		private:
			pointer	_ptr;
		public:
			random_access_iterator(const random_access_iterator& x) : _ptr(x._ptr) {return ;}
			random_access_iterator(pointer ptr = NULL) : _ptr(ptr) {return ;}
			~random_access_iterator(void) { return ;}

			// a == b
			bool	operator== (random_access_iterator b)
			{
				return this->_ptr == b._ptr;
			}
			// a != b
			bool	operator!= (random_access_iterator b)
			{
				return this->_ptr != b._ptr;
			}
			// *a
			reference	operator* (void)
			{
				return *(this->_ptr);
			}
			// a->m
			pointer	operator-> (void)
			{
				return this->_ptr;
			}
			// a++
			random_access_iterator	operator++ (int)
			{
				random_access_iterator old = *this;

				this->_ptr++;
				return (old);
			}
			// ++a
			random_access_iterator&	operator++ ()
			{
				this->_ptr++;
				return *this;
			}
			// a--
			random_access_iterator	operator-- (int)
			{
				random_access_iterator old = *this;

				this->_ptr--;
				return (old);
			}
			// --a
			random_access_iterator&	operator-- ()
			{
				this->_ptr--;
				return *this;
			}
			// *a++, doet ie gwn automatisch toch??
			// a + n
			random_access_iterator	operator+ (int n)
			{
				return random_access_iterator(this->_ptr + n);
			}
			// n + a heel erg speciaal, maar kan daarna gewoon a + n oproepen
			// a - n
			random_access_iterator	operator- (int n)
			{
				return random_access_iterator(this->_ptr - n);
			}
			// a - b
			difference_type	operator- (random_access_iterator b)
			{
				return (this->_ptr - b._ptr);
			}
			// a < b
			bool	operator< (random_access_iterator b)
			{
				return this->_ptr < b._ptr;
			}
			// a > b
			bool	operator> (random_access_iterator b)
			{
				return this->_ptr > b._ptr;
			}
			// a <= b
			bool	operator<= (random_access_iterator b)
			{
				return this->_ptr <= b._ptr;
			}
			// a >= b
			bool	operator>= (random_access_iterator b)
			{
				return this->_ptr >= b._ptr;
			}
			// a += n
			random_access_iterator	operator+= (int n)
			{
				this->_ptr += n;
				return *this;
			}
			// a -= n
			random_access_iterator	operator-=(int n)
			{
				this->_ptr -= n;
				return *this;
			}
			// a[n]
			value_type&	operator[] (difference_type n)
			{
				return *(this->_ptr + n);
			}

	};
} //end namespace

#undef itr

#endif
