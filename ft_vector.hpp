/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 10:59:42 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/03/31 15:21:16 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include <exception>
# include "ft_random_access_iterator.hpp"
# include "ft_utils.hpp"
# include "type_traits.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		//////////////
		// typedefs //
		//////////////
		public:
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef value_type&											reference;
			typedef const value_type&									const_reference;
			typedef value_type*											pointer;
			typedef const value_type*									const_pointer;
			typedef random_access_iterator<T, T*, T&>					iterator;
			typedef random_access_iterator<T, const T*, const T&>		const_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type					size_type;

		private:
			pointer					_array;
			size_type				_capacity;
			size_type				_size;
			allocator_type			_alloc;

			void		_addNewElement (const value_type& val, size_type index)
			{
				this->_alloc.construct(&(this->_array[index]), val);
				this->_size++;
			}

			void		_resizeArray (size_type capacity, size_type len)
			{
				T*	temp;

				if (capacity > 0)
					temp = this->_alloc.allocate(capacity);
				else
					temp = NULL;
				for (size_type i = 0; i < len; i++)
					this->_alloc.construct(&(temp[i]), this->_array[i]);
				this->clear();
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_size = len;
				this->_capacity = capacity;
				this->_array = temp;
			}

		public:
			///////////////
			// Iterators //
			///////////////
			iterator begin ()
			{
				return (iterator(this->_array));
			}

			const_iterator begin () const
			{
				return (const_iterator(this->_array));
			}

			iterator end ()
			{
				return (iterator(this->_array) + this->_size);
			}

			const_iterator end () const
			{
				return (const_iterator(this->_array) + this->_size);
			}

			// reverse_iterator rbegin()
			// {

			// }

			// const_reverse_iterator rbegin() const
			// {

			// }

			// reverse_iterator rend()
			// {

			// }

			// const_reverse_iterator rend() const
			// {

			// }
			//////////////
			// Capacity //
			//////////////

			size_type		size (void) const {return this->_size;}
			size_type		max_size (void) const {return this->_alloc.max_size();}
			size_type		capacity (void) const {return this->_capacity;}
			bool			empty (void) const {return this->_size == 0;}
			allocator_type	get_allocator (void) const {return this->_alloc;}

			void resize (size_type n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					for (size_type i = this->_size - n; i > 0; i--)
						this->pop_back();
				}
				else if (n > this->_capacity)
				{
					if (n > this->_capacity * 2)
						this->_resizeArray(n, this->_size);
					else
						this->_resizeArray(this->_capacity * 2, this->_size);
				}
				for (size_type i = this->_size; i < n; i++)
					this->push_back(val);
			}

			void reserve (size_type n)
			{
				if (n > this->_capacity)
				{
					if (n > this->max_size())
						throw std::length_error("vector [void reserve(size_type n)]");
					this->_resizeArray(n, this->_size);
				}
			}

			////////////////////
			// Element access //
			////////////////////

			reference	operator[] (size_type n){return this->_array[n];}
			const_reference	operator[] (size_type n) const {return this->_array[n];}

			reference at (size_type n)
			{
				if (n >= this->_size)
					throw std::out_of_range("vector [reference at(size_type n)]");
				return (this->_array[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= this->_size)
					throw std::out_of_range("vector [const_reference at(size_type n)]");
				return (this->_array[n]);
			}

			reference front (){return this->_array[0];}
			const_reference front () const {return this->_array[0];}
			reference back (){return this->_array[this->_size - 1];}
			const_reference back () const {return this->_array[this->_size - 1];}

			///////////////
			// modifiers //
			///////////////

			// nog doen, nog geen iterator
			//protecten maar dat wil ik nu niet
			template <class InputIterator>
			typename ft::enable_if<ft::is_inputiterator<InputIterator>::value, void>::type	assign (InputIterator first, InputIterator last)
			{
				this->clear();
				this->reserve(ft::distance(first, last));
				for(; first != last; first++)
					this->push_back(*first);
			}

			void assign (size_type n, const value_type& val)
			{
				this->clear();
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

			void	pop_back (void)
			{
				this->_size--;
				this->_alloc.destroy(&(this->_array[this->_size]));
			}

			void push_back (const value_type& val)
			{
				if (this->_size == this->_capacity)
					resize(this->_size + 1, val);
				else
					this->_addNewElement(val, this->_size);
			}

		private:
			size_type _shiftElements (size_type i_dst, size_type i_srcs, size_type amountToConstruct, size_type amountToMove)
			{
				if (this->_size + amountToConstruct > this->_capacity)
				{
					if (this->_size + amountToConstruct > this->_capacity * 2)
						this->_resizeArray(this->_size + amountToConstruct, this->_size);
					else
						this->_resizeArray(this->_capacity * 2, this->_size);
				}
				for (; amountToMove > 0; amountToMove--)
				{
					if (amountToConstruct > 0)
						this->_addNewElement(this->_array[i_srcs], i_dst);
					else
						this->_array[i_dst] = this->_array[i_srcs];
					i_dst--;
					i_srcs--;
					if (amountToConstruct > 0)
						amountToConstruct--;
				}
				return (amountToConstruct);
			}

		private:
			size_type	_assignElement (size_type amountToConstruct, size_type i_dst, const value_type& val)
			{
				if (amountToConstruct > 0)
					this->_addNewElement(val, i_dst);
				else
					this->_array[i_dst] = val;
				if (amountToConstruct > 0)
					amountToConstruct--;
				return (amountToConstruct);
			}

		public:
			void		insert (iterator position, size_type n, const value_type& val)
			{
				difference_type amountToConstruct;
				difference_type amountToMove;

				if (n == 0)
					return ;
				difference_type pos = ft::distance(this->begin(), position);
				amountToMove = this->_size - pos;
				amountToConstruct = this->_shiftElements(this->_size + n - 1, pos + amountToMove - 1, n, amountToMove);
				difference_type i_dst = pos + n - 1;
				for (; n > 0; n--)
				{
					amountToConstruct = this->_assignElement(amountToConstruct, i_dst, val);
					i_dst--;
				}
			}

			template <class InputIterator>
			typename ft::enable_if<ft::is_inputiterator<InputIterator>::value, void>::type	insert (iterator position, InputIterator first, InputIterator last)
			{

				difference_type amountNewElements = ft::distance(first, last);
				if (amountNewElements == 0)
					return ;
				difference_type pos = ft::distance(this->begin(), position);
				difference_type amountToMove = this->_size - pos;
				difference_type amountToConstruct = this->_shiftElements(this->_size + amountNewElements - 1, pos + amountToMove - 1, amountNewElements, amountToMove);
				difference_type i_dst = pos + amountNewElements - 1;

				for (; amountNewElements > 0; amountNewElements--)
				{
					last--;
					amountToConstruct = this->_assignElement(amountToConstruct, i_dst, *last);
					i_dst--;
				}

			}

			iterator	insert (iterator position, const value_type& val)
			{
				difference_type pos = ft::distance(this->begin(), position);
				this->insert(position, 1, val);
				return (this->begin() + pos);
			}

			iterator	erase (iterator first, iterator last)
			{
				difference_type amountToErase = ft::distance(first, last);
				difference_type amountToShift = ft::distance(last, this->end());
				difference_type i_dst = ft::distance(this->begin(), first);
				difference_type i_src = ft::distance(this->begin(), last);

				for (difference_type i = 0; i < amountToShift; i++)
					this->_array[i_dst + i] = this->_array[i_src + i];
				for (difference_type i = 0; i < amountToErase; i++)
					this->pop_back();
				return (first);
			}

			iterator	erase (iterator position)
			{
				return (this->erase(position, position + 1));
			}

			void	swap (vector& x)
			{
				ft::swap(this->_array, x._array);
				ft::swap(this->_capacity, x._capacity);
				ft::swap(this->_size, x._size);
			}

			void	clear ()
			{
				while (this->empty() == false)
					this->pop_back();
			}

			/////////////////////////
			// assignment operator //
			/////////////////////////
			vector&	operator= (const vector& x)
			{
				this->_alloc = x._alloc;
				this->assign(x.begin(), x.end());
				return *this;
			}

			//////////////////
			// constructors //
			//////////////////
			vector (const vector& x) : _array(NULL), _capacity(0), _size(0), _alloc(x._alloc)
			{
				this->_resizeArray(x._size, 0);
				for (size_type i = 0; i < x._size; i++)
					this->push_back(x._array[i]);
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _array(NULL), _capacity(0), _size(0), _alloc(alloc)
			{
				this->_resizeArray(n, 0);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<ft::is_inputiterator<InputIterator>::value>::type* = NULL) : _array(NULL), _capacity(0), _size(0), _alloc(alloc)
			{
				this->_resizeArray(ft::distance(first , last), 0);
				for (; first != last; first++)
					this->push_back(*first);
			}

			explicit vector (const allocator_type& alloc = allocator_type()) : _array(NULL), _capacity(0), _size(0), _alloc(alloc)
			{
				return ;
			}

			/////////////////
			// destructors //
			/////////////////
			~vector (void)
			{
				if (this->_size > 0)
				{
					this->clear();
					this->_alloc.deallocate(this->_array, this->_capacity);
				}
				return ;
			}
	};

	///////////////////////////
	// operator declerations //
	///////////////////////////
	template< class T, class Alloc >
	bool	operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool	operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template< class T, class Alloc >
	bool	operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Alloc >
	bool	operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template< class T, class Alloc >
	bool	operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template< class T, class Alloc >
	bool	operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
} //end namespace

#endif
