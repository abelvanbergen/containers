/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 09:42:42 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/11/05 11:14:44 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

# include "type_traits.hpp"

namespace ft{

	template< typename U>
	void		swap (U& x, U& y)
	{
		U	swap(x);

		x = y;
		y = swap;
	}

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			first1++;
			first2++;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	int max (int a, int b) {return (a > b ? a : b); }

	template <class T>
	struct less : binary_function <T,T,bool>
	{
  		bool operator() (const T& x, const T& y) const {return x<y;}
	};

	template <typename Iterator>
    typename ft::iterator_traits<Iterator>::difference_type	distance (Iterator pos1, Iterator pos2)
    {
        return distance (pos1, pos2, ft::iterator_traits<Iterator>::iterator_category()); 
    }
	template <typename RAI>
    typename ft::iterator_traits<RAI>::difference_type	distance (RAI first_position, RAI second_position, ft::random_access_iterator_tag) 
    {
        return second_position - first_position; 
    }

	template <typename InputIterator>
    typename ft::iterator_traits<II>::difference_type	distance (II first_position, II second_position, ft::input_iterator_tag) 
    {
        typename ft::iterator_traits<II>::difference_type diff;
        for (diff=0; first_position != second_position; ++first_position)
			diff++
        return diff; 
    }  

} //end namespace

#endif
