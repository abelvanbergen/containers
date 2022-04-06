/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_iterator.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 13:13:00 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/04 18:14:24 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

# include "type_traits.hpp"

namespace ft {
	template <class Iter>
	class reverse_iterator
	{
		public:
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;
			typedef typename Iter::iterator_category	iterator_category;
			typedef typename Iter::const_iterator		const_iter;
			typedef reverse_iterator<const_iter>		const_reverse_iter;
			

		private:
			Iter	_base;
		public:
			reverse_iterator&	operator=(const reverse_iterator& obj)
			{
				this->_base = obj._base;
				return *this;
			}

			reverse_iterator(const reverse_iterator& obj)
			{
				*this = obj;
			}

			reverse_iterator()
			{
				return ;
			}

			~reverse_iterator()
			{
				return ;
			}
			
			explicit reverse_iterator (Iter it) : _base(it)
			{
				return ;
			}

			Iter base() const
			{
				return (this->_base);
			}

			reference operator* () const
			{
				return *(this->_base);
			}

			pointer operator->() const
			{
				return this->_base;
			}

			reference operator[] (difference_type n) const
			{
				return *(this->_base + n);
			}
			
			reverse_iterator operator+ (difference_type n) const
			{
				return (this->_base - n);
			}
			
			reverse_iterator& operator++()
			{
				this->_base--;
				return (*this);
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator	old = *this;

				--this->_base;
				return (old);
			}
			
			reverse_iterator& operator+= (difference_type n)
			{
				this->_base -= n;
				return *this;
			}
			
			reverse_iterator operator- (difference_type n) const
			{
				return (this->_base + n);
			}
			
			reverse_iterator& operator--()
			{
				this->_base++;
				return (*this);
			}
			reverse_iterator  operator--(int)
			{
				reverse_iterator	old = *this;

				++this->_base;
				return (old);
			}
			reverse_iterator& operator-= (difference_type n)
			{
				this->_base += n;
				return *this;
			}
	};

	// template <class Iterator>
	// bool	operator== (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	// {
	// 	return lhs._base == rhs._base;
	// }

	// template <class Iterator>
	// bool	operator!= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	// {
	// 	return lhs._base != rhs._base;
	// }

	// template <class Iterator>
	// bool	operator< (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	// {
	// 	return lhs._base > rhs._base;
	// }

	// template <class Iterator>
	// bool	operator<= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	// {
	// 	return lhs._base >= rhs._base;
	// }

	// template <class Iterator>
	// bool	operator> (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	// {
	// 	return lhs._base < rhs._base;
	// }

	// template <class Iterator>
	// bool	operator>= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	// {
	// 	return lhs._base <= rhs._base;
	// }
} //end namespace

#endif
