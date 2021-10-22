/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pair.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 10:53:17 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/10/18 16:14:26 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_HPP
# define FT_PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct pair
	{
		public:
			typedef T1		first_type;
			typedef T2		second_type;

			first_type		first;
			second_type		second;

			/////////////////////////
			// Assignment operator //
			/////////////////////////

			pair&	operator= (const pair& pr)
			{
				this->first = pr.first;
				this->second = pr.second;
				return *this;
			}

			//////////////////
			// constructors //
			//////////////////

			pair (const first_type& a, const second_type& b) : first(a), second(b)
			{
				return ;
			}

			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
			{
				return ;
			}

			pair() : first(T1()), second(T2())
			{
				return ;
			}

			////////////////
			// destructor //
			////////////////
			~pair()
			{
				return ;
			}
	}; //end struct pair

	///////////////////////////////////
	// NON-MEMBER FUNCTION OVERLOADS //
	///////////////////////////////////

	template <class T1, class T2>
	bool	operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first) && (lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool	operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool	operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
	bool	operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs<lhs);
	}

	template <class T1, class T2>
	bool	operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs<lhs;
	}

	template <class T1, class T2>
	bool	operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs<rhs);
	}

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}

} //end namespace

#endif

