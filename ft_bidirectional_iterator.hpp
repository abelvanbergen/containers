/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bidirectional_iterator.hpp                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 13:15:26 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/10/20 11:17:54 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

#include "ft_mapNodes.hpp"

namespace ft {
	template <class T, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
	class bidirectional_iterator
	{
		public:
			typedef T						value_type;
			typedef size_t					difference_type;
			typedef value_type*				pointer;
			typedef value_type&				reference;
			typedef ft::mapNode<value_type>	node;
			typedef node*					node_pointer;

		private:
			node_pointer	_ptr;

		public:
			reference	operator* (void)
			{
				return (this->data);
			}

			pointer	operator->(void)
			{
				return (this->data);
			}

			// a++
			bidirectional_iterator	operator++(int)
			{
				bidirectional_iterator old = *this;

				this->_ptr++;
				return (old);
			}
			// ++a
			bidirectional_iterator&	operator++()
			{
				this->_ptr++;
				return *this;
			}

			// a--
			bidirectional_iterator	operator--(int)
			{
				bidirectional_iterator old = *this;

				this->_ptr--;
				return (old);
			}
			// --a
			bidirectional_iterator&	operator--()
			{
				this->_ptr--;
				return *this;
			}

			bidirectional_iterator&	operator= (const bidirectional_iterator& srcs)
			{
				this->ptr = srcs._ptr;
				return *this;
			}

			bidirectional_iterator (const bidirectional_iterator& srcs)
			{
				this->_ptr = srcs._ptr;
				return ;
			}

			bidirectional_iterator (pointer ptr = NULL) : _ptr(ptr) {return ;}

			~bidirectional_iterator (void){ return ;}

			// template <class T, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
			// friend bool	bidirectional::operator== (const bidirectional& lhs, const bidirectional& rhs);
	}; //end bidirectional iterator class

	// template <class bidirectional>
	// bool	bidirectional::operator== (const bidirectional& lhs, const bidirectional& rhs)
	// {
	// 	return (lhs == rhs);
	// }
	// template <class bidirectional>
	// bool	bidirectional::operator!= (const bidirectional& lhs, const bidirectional& rhs)
	// {
	// 	return !(lhs == rhs);
	// }
} //end namespace

#endif