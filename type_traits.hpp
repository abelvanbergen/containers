/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_traits.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 11:36:33 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/10/12 11:57:50 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class T>
	struct iterator_traits {
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef random_access_iterator_tag			iterator_category;
		typedef T*									pointer;
		typedef T&									reference;
	};
}//end namespace

#endif
