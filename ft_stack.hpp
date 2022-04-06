/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 11:18:15 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/05 11:59:51 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include "ft_vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T										value_type;
			typedef Container								container_type;
			typedef typename container_type::size_type		size_type;

		protected:
			container_type	_cntr;
	
		public:
			stack&	operator= (const stack& obj)
			{
				this->_cntr = obj._cntr;
				return *this;
			}

			stack(const stack& obj)
			{
				*this = obj;
			}

			explicit stack (const container_type& ctnr = container_type()) : _cntr(ctnr)
			{
				
			}

			~stack () {}

			bool	empty () const
			{
				return this->_cntr.empty();
			}

			size_type	size () const
			{
				return this->_cntr.size();
			}

			value_type&	top ()
			{
				return this->_cntr.back();
			}

			const value_type&	top () const
			{
				return this->_cntr.back();
			}

			void	push (const value_type& val)
			{
				this->_cntr.push_back(val);
			}

			void pop ()
			{
				this->_cntr.pop_back();
			}

	}; //end stack

	///////////////////////////
	// operator declerations //
	///////////////////////////
	template <class T, class Container >
	bool	operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs._cntr == rhs._cntr);
	}

	template <class T, class Container >
	bool	operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container >
	bool	operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs._cntr < rhs._cntr);
	}

	template <class T, class Container >
	bool	operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Container >
	bool	operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container >
	bool	operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return !(lhs < rhs);
	}
} //end namespace

#endif
