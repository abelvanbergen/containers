/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_random_access_iterator.hpp                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 09:22:52 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/16 10:53:11 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# define FT_RANDOM_ACCESS_ITERATOR_HPP

# define itr ft::iterator<T, Distance, Pointer, Reference>

# include <ft_type_traits.hpp>

namespace ft {
	template <class T, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
	class random_access_iterator
	{
		//////////////
		// typedefs //
		//////////////
		public:
			typedef T														value_type;
			typedef Distance  												difference_type;
			typedef Pointer													pointer;
			typedef Reference												reference;
			typedef random_access_iterator_tag								iterator_category;

			typedef random_access_iterator <T, T*, T&>						iterator;
			typedef random_access_iterator <T, const T*, const T&>			const_iterator;

		private:
			pointer	_ptr;

			/////////////////
			// constructor //
			/////////////////
		public:
			random_access_iterator(const random_access_iterator& x) : _ptr(x._ptr)
			{
				return ;
			}

			random_access_iterator(pointer ptr = NULL) : _ptr(ptr)
			{
				return ;
			}

			/////////////////////////
			// assignment operator //
			/////////////////////////
			random_access_iterator&	operator= (const random_access_iterator& srcs)
			{
				this->_ptr = srcs._ptr;
				return *this;
			}

			////////////////
			// destructor //
			////////////////
			~random_access_iterator(void)
			{
				return ;
			}

			///////////////
			// operators //
			///////////////
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
			// a + n
			random_access_iterator	operator+ (int n) const
			{
				return random_access_iterator(this->_ptr + n);
			}
			// a - n
			random_access_iterator	operator- (int n) const
			{
				return random_access_iterator(this->_ptr - n);
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
			reference	operator[] (const difference_type& n)
			{
				return *(this->_ptr + n);
			}
		
			//////////////////////////////////
			// Implicit conversion operator //
			//////////////////////////////////
		public:
			operator const_iterator() const
			{
				return (const_iterator(this->_ptr));
			}

			////////////
			// friend //
			////////////
			template <class T1, class T2, class T3>
			friend bool	operator==(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs);

			template <class T1, class T2, class T3>
			friend bool	operator<(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs);

			template <class T1, class T2, class T3>
			friend typename ft::iterator_traits<random_access_iterator< T1, T2*, T2& > >::difference_type	operator-(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs);
	}; //end random acccess iterator class

	///////////////////////////////////
	// Non-member function overloads //
	///////////////////////////////////
	// // n + a
	template <class T>
	random_access_iterator<T, T*, T&>	operator+(typename random_access_iterator< T, T*, T& >::difference_type const &n, random_access_iterator< T, T*, T& > const &iterator)
	{
		return (iterator + n);
	}
	
	// a - b
	template <class T1, class T2, class T3>
	typename ft::iterator_traits<random_access_iterator< T1, T2*, T2& > >::difference_type	operator-(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs)
	{
		return (lhs._ptr - rhs._ptr);
	}
	// a == b
	template <class T1, class T2, class T3>
	bool	operator==(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	
	// a != b
	template <class T1, class T2, class T3>
	bool	operator!=(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs)
	{
		return !(lhs == rhs);
	}

	// a < b
	template <class T1, class T2, class T3>
	bool	operator<(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs)
	{
		return (lhs._ptr < rhs._ptr);
	}

	// a > b
	template <class T1, class T2, class T3>
	bool	operator>(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs)
	{
		return (rhs < lhs);
	}

	// a <= b
	template <class T1, class T2, class T3>
	bool	operator<=(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs)
	{
		return (!(rhs < lhs));
	}

	// a >= b
	template <class T1, class T2, class T3>
	bool	operator>=(random_access_iterator< T1, T2*, T2& > const &lhs, random_access_iterator< T1, T3*, T3& > const &rhs)
	{
		return (!(lhs < rhs));
	}

} //end namespace

#undef itr

#endif
