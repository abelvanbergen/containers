/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bidirectional_iterator.hpp                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 13:15:26 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/16 10:58:41 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

# include <ft_mapNodes.hpp>
# include <ft_type_traits.hpp>

namespace ft {
	template <class T, class Node, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
	class bidirectional_iterator
	{
		//////////////
		// typedefs //
		//////////////
		public:
			typedef T															value_type;
			typedef size_t														difference_type;
			typedef value_type*													pointer;
			typedef value_type&													reference;
			typedef Node*														node_pointer;
			typedef bidirectional_iterator_tag									iterator_category;
			typedef ft::bidirectional_iterator <T, Node, const T*, const T&>	const_iterator;

		private:
			node_pointer	_ptr;
		public:
			/////////////////
			// constructor //
			/////////////////
			bidirectional_iterator (const bidirectional_iterator& srcs)
			{
				this->_ptr = srcs._ptr;
				return ;
			}

			bidirectional_iterator (node_pointer ptr = NULL) : _ptr(ptr)
			{
				return ;
			}

			/////////////////////////
			// assignment operator //
			/////////////////////////
			bidirectional_iterator&	operator= (const bidirectional_iterator& srcs)
			{
				this->_ptr = srcs._ptr;
				return *this;
			}

			////////////////
			// destructor //
			////////////////
			~bidirectional_iterator (void)
			{
				return ;
			}

			///////////////
			// operators //
			///////////////
			reference	operator* (void)
			{
				return (this->_ptr->data);
			}

			pointer	operator->(void)
			{
				return (&this->_ptr->data);
			}

			// a++
			bidirectional_iterator	operator++(int)
			{
				bidirectional_iterator old = *this;

				this->_ptr = this->_ptr->_next();
				return (old);
			}
			// ++a
			bidirectional_iterator&	operator++()
			{
				this->_ptr = this->_ptr->_next();
				return *this;
			}

			// a--
			bidirectional_iterator	operator--(int)
			{
				bidirectional_iterator old = *this;

				this->_ptr = this->_ptr->_prev();
				return (old);
			}
			// --a
			bidirectional_iterator&	operator--()
			{
				this->_ptr = this->_ptr->_prev();
				return *this;
			}

			node_pointer	get_ptr() const
			{
				return (_ptr);
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
			template <class T1, class N, class T2, class T3>
			friend bool	operator== (bidirectional_iterator< T1, N, T2*, T2& > const &lhs, bidirectional_iterator< T1, N, T3*, T3& > const &rhs);

	}; //end bidirectional iterator class

	///////////////////////////////////
	// Non-member function overloads //
	///////////////////////////////////
	template <class T1, class N, class T2, class T3>
	bool	operator== (bidirectional_iterator< T1, N, T2*, T2& > const &lhs, bidirectional_iterator< T1, N, T3*, T3& > const &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}

	template <class T1, class N, class T2, class T3>
	bool	operator!= (bidirectional_iterator< T1, N, T2*, T2& > const &lhs, bidirectional_iterator< T1, N, T3*, T3& > const &rhs)
	{
		return !(lhs == rhs);
	}
} //end namespace

#endif
