/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_iterator.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 13:13:00 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/15 21:09:32 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

# include <ft_type_traits.hpp>

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
			typedef typename Iter::const_iterator		const_iterator;
			typedef reverse_iterator<const_iterator>	const_reverse_iterator;
			

		private:
			Iter	_base;
		public:
			/////////////////
			// constructor //
			/////////////////
			reverse_iterator(const reverse_iterator& obj)
			{
				*this = obj;
			}

			reverse_iterator()
			{
				return ;
			}
			
			reverse_iterator (Iter it) : _base(it)
			{
				return ;
			}

			/////////////////////////
			// assignment operator //
			/////////////////////////
			reverse_iterator&	operator=(const reverse_iterator& obj)
			{
				this->_base = obj._base;
				return *this;
			}

			////////////////
			// destructor //
			////////////////
			~reverse_iterator()
			{
				return ;
			}

			//////////////////////
			// member functions //
			//////////////////////
			Iter base() const
			{
				return (this->_base);
			}

			reference operator* ()
			{
				return *(this->_base);
			}

			pointer operator->()
			{
				return &(*(this->_base));
			}

			reference operator[] (difference_type n)
			{
				return (this->_base[-n]);
			}
			
			reverse_iterator operator+ (const difference_type n) const
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
			
			reverse_iterator& operator+= (const difference_type n)
			{
				this->_base -= n;
				return *this;
			}
			
			reverse_iterator operator- (const difference_type n) const
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

			public:
			
			operator const_reverse_iterator() const
			{
				return (const_reverse_iterator(this->_base));
			}

			////////////
			// friend //
			////////////
			template <class IteratorLeft, class IteratorRight>
			friend bool	operator==(const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs);

			template <class IteratorLeft, class IteratorRight>
			friend bool	operator<(const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs);

			template <class IteratorLeft, class IteratorRight>
			friend typename ft::iterator_traits<reverse_iterator<IteratorLeft> >::difference_type	operator-(reverse_iterator<IteratorLeft>& left, reverse_iterator<IteratorRight>& right);
	};

	///////////////////////////////////
	// Non-member function overloads //
	///////////////////////////////////
	template <class IteratorLeft, class IteratorRight>
	typename ft::iterator_traits<reverse_iterator<IteratorLeft> >::difference_type	operator-(reverse_iterator<IteratorLeft>& left, reverse_iterator<IteratorRight>& right)
	{
		return (left._base - right._base);
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type const & n, const reverse_iterator<Iterator>& iterator)
	{
		return (iterator + n);
	}

	template <class IteratorLeft, class IteratorRight>
	bool	operator== (const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs)
	{
		return lhs._base == rhs._base;
	}

	template <class IteratorLeft, class IteratorRight>
	bool	operator!= (const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class IteratorLeft, class IteratorRight>
	bool	operator< (const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs)
	{
		return lhs._base > rhs._base;
	}

	template <class IteratorLeft, class IteratorRight>
	bool	operator<= (const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class IteratorLeft, class IteratorRight>
	bool	operator> (const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs)
	{
		return (rhs < lhs);
	}

	template <class IteratorLeft, class IteratorRight>
	bool	operator>= (const reverse_iterator<IteratorLeft>& lhs, const reverse_iterator<IteratorRight>& rhs)
	{
		return (!(lhs < rhs));
	}
} //end namespace

#endif
