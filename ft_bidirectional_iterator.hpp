/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bidirectional_iterator.hpp                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 13:15:26 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/05 17:43:53 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

# include "ft_mapNodes.hpp"
# include "type_traits.hpp"

namespace ft {
	template <class T, class Node, class Pointer = T*, class Reference = T&, class Distance = ptrdiff_t>
	class bidirectional_iterator
	{
		public:
			typedef T												value_type;
			typedef size_t											difference_type;
			typedef value_type*										pointer;
			typedef value_type&										reference;
			typedef Node*											node_pointer;
			typedef bidirectional_iterator_tag						iterator_category;
	
			typedef ft::bidirectional_iterator <T, Node, const T*, const T&>	const_iterator;

		private:
			node_pointer	_ptr;
		public:
			bool	operator== (bidirectional_iterator b)
			{
				return this->_ptr == b._ptr;
			}
			// a != b
			bool	operator!= (bidirectional_iterator b)
			{
				return this->_ptr != b._ptr;
			}
			
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

			bidirectional_iterator&	operator= (const bidirectional_iterator& srcs)
			{
				this->_ptr = srcs._ptr;
				return *this;
			}

			bidirectional_iterator (const bidirectional_iterator& srcs)
			{
				this->_ptr = srcs._ptr;
				return ;
			}

			node_pointer	get_ptr() const
			{
				return (_ptr);
			}

			bidirectional_iterator (node_pointer ptr = NULL) : _ptr(ptr) {return ;}

			~bidirectional_iterator (void){ return ;}

		public:
			operator const_iterator() const
			{
				return (const_iterator(this->_ptr));
			}

	}; //end bidirectional iterator class
} //end namespace

#endif
