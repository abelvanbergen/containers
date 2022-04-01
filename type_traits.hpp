/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_traits.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 11:36:33 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/03/31 15:17:27 by avan-ber      ########   odam.nl         */
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

	template <bool, class T>
	struct _iterator_traits{
	};

	template <class T>
	struct _iterator_traits<true, T> {
		typedef typename T::value_type				value_type;
		typedef typename T::difference_type			difference_type;
		typedef typename T::iterator_category		iterator_category;
		typedef typename T::pointer					pointer;
		typedef typename T::reference				reference;
	};

	template <class T>
	struct hasIteratorTypedefs 
	{
		private:
			template<class U>
			static int	ingmartest(...);

			template<class U>
			static char	ingmartest(	typename U::value_type*,
									typename U::difference_type*,
									typename U::iterator_category*,
									typename U::pointer*);
		
		public:
			static const bool value = sizeof(ingmartest<T>(0, 0, 0, 0)) == sizeof(char);
	};

	template <class T>
	struct hasIteratorCategory
	{
		private:
			template<class U>
			static int	ingmartest (...);

			template<class U>
			static char	ingmartest (typename U::iterator_category*);
		
		public:
			static const bool value = sizeof(ingmartest<T>(0)) == sizeof(char);
	};

	template<class T>
	struct iterator_traits : ft::_iterator_traits<ft::hasIteratorTypedefs<T>::value, T > {};

	template <class T>
	struct iterator_traits<T*> {
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef random_access_iterator_tag			iterator_category;
		typedef T*									pointer;
		typedef T&									reference;
	};

	template <bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<const bool v>
	struct bool_constant
	{
		static const bool value = v;
	};

	struct	falseType : bool_constant<false> {};
	struct	trueType : bool_constant<true> {};

	template <class T, class U, bool = hasIteratorCategory<T>::value> 
	struct hasIteratorCategoryTo : ft::bool_constant< std::is_convertible<typename T::iterator_category, U>::value > {};

	template <class T, class U>
	struct hasIteratorCategoryTo<T, U,false> : ft::falseType {};

	template <class T>
	struct	is_inputiterator : ft::hasIteratorCategoryTo<T, ft::input_iterator_tag> {};

	template <class T>
	struct	is_bidirectional_iterator : ft::hasIteratorCategoryTo<T, ft::bidirectional_iterator_tag> {};

	template <class T>
	struct	is_random_acces_iterator : ft::hasIteratorCategoryTo<T, ft::random_access_iterator_tag> {};

}//end namespace

#endif
