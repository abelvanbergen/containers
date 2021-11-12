/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bidirectional_iterator.hpp                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 13:15:26 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/11/11 08:42:54 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

# include "ft_mapNodes.hpp"
# include "type_traits.hpp"

namespace ft {
	template <class T, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
	class bidirectional_iterator
	{
		public:
			typedef T												value_type;
			typedef size_t											difference_type;
			typedef value_type*										pointer;
			typedef value_type&										reference;
			typedef ft::mapNode<value_type>							node;
			typedef node*											node_pointer;
			typedef bidirectional_iterator_tag						iterator_category;

			typedef	bidirectional_iterator <T, T*, T&>				iterator;
			typedef bidirectional_iterator <T, const T*, const T&>	const_iterator;

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

			bidirectional_iterator (const node_pointer ptr = NULL) : _ptr(ptr) {return ;}

			~bidirectional_iterator (void){ return ;}

		public:
			operator iterator() const
			{
				return (iterator(this->_ptr));
			}

			operator const_iterator() const
			{
				return (const_iterator(this->_ptr));
			}

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
