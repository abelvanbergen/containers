/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 09:13:43 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/08 20:46:39 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <memory>
# include <exception>

# include "ft_bidirectional_iterator.hpp"
# include "ft_reverse_iterator.hpp"
# include "ft_mapNodes.hpp"
# include "ft_pair.hpp"
# include "ft_utils.hpp"
# include <stdlib.h>

namespace ft {
	template <class Key, class T, class Compare = std::less<const Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		//////////////
		// typedefs //
		//////////////
		public:
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef ft::pair<const key_type, mapped_type>								value_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef value_type&															reference;
			typedef const value_type&													const_reference;
			typedef value_type*															pointer;
			typedef	const value_type*													const_pointer;
			typedef typename allocator_type::size_type									size_type;
		private:
			typedef mapNode<value_type>													node;
			typedef node*																node_pointer;
			typedef typename Alloc::template rebind<node>::other						node_alloc;
		public:
			typedef ft::bidirectional_iterator<value_type, node>						iterator;
			typedef typename iterator::const_iterator									const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type					difference_type;

		public:
			class value_compare
			{
				protected:
  					Compare	comp;
					value_compare (Compare c) : comp(c) {return ;}
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
				friend class map;
			};

		private:
			node_pointer			_firstSentinel;
			node_pointer			_lastSentinel;
			node_pointer			_root;
			size_type				_size;
			key_compare				_compare;
			value_compare			_valueCompare;
			node_alloc				_alloc;

			///////////////////
			// BST functions //
			///////////////////

			node_pointer	_rightRotate (node_pointer y)
			{
				node_pointer x = y->left;
				node_pointer T2 = x->right;

				x->parent = y->parent;
				y->parent = x;
				if (T2)
					T2->parent = y;
				x->right = y;
				y->left = T2;

				this->_updateHeight(y);
				this->_updateHeight(x);

				return x;
			}

			node_pointer	_leftRotate (node_pointer x)
			{
				node_pointer y = x->right;
				node_pointer T2 = y->left;

				y->parent = x->parent;
				x->parent = y;
				if (T2)
					T2->parent = x;
				y->left = x;
				x->right = T2;

				this->_updateHeight(x);
				this->_updateHeight(y);
				return y;
			}

			node_pointer	_balanceForInsertion(node_pointer root, const value_type& value)
			{
				int balance = _getBalance(root);
				if (balance < -1 && root->left == NULL)
					return this->_leftRotate(root);
				// Left Left Case
				if (balance > 1 && this->_valueCompare(value, root->left->data))
					return this->_rightRotate(root);
				// Right Right Case
				if (balance < -1 && this->_valueCompare(root->left->data, value))
					return this->_leftRotate(root);
				// Left Right Case
				if (balance > 1 && this->_valueCompare(root->left->data, value)) //Left Right Case
				{
					root->left = this->_leftRotate(root->left);
					return this->_rightRotate(root);
				}
				// Right Left Case
				if (balance < -1 && this->_valueCompare(value, root->left->data)) //Right Left Case
				{
					root->right = this->_rightRotate(root);
					return this->_leftRotate(root);
				}
				return root;
			}

			node_pointer	_balanceForDeletion(node_pointer root)
			{
				int balance = this->_getBalance(root);
				if (balance > 1 && this->_getBalance(root->left) >= 0)
					return this->_rightRotate(root);
				if (balance > 1 && this->_getBalance(root->left) < 0)
				{
					root->left = this->_leftRotate(root->left);
					return this->_rightRotate(root);
				}
				if (balance < -1 && this->_getBalance(root->right) <= 0)
					return this->_leftRotate(root);
				if (balance < -1 && this->_getBalance(root->right) > 0)
				{
					root->right = this->_rightRotate(root->right);
					return this->_leftRotate(root);
				}
				return root;
			}

			node_pointer	_insertNewNode(node_pointer root, const value_type& value, node_pointer parent)
			{
				if (!root)
					return (this->_newNode(value, parent));
				if (this->_valueCompare(value, root->data))
					root->left = _insertNewNode(root->left, value, root);
				else if (this->_valueCompare(root->data, value))
					root->right = _insertNewNode(root->right, value, root);
				else
					return (root);
				this->_updateHeight(root);
				return this->_balanceForInsertion(root, value);
			}

			node_pointer	_newNode (const value_type& value, node_pointer parent)
			{
				node_pointer newNode = this->_alloc.allocate(1);

				this->_alloc.construct(newNode, value);
				newNode->parent = parent;
				newNode->firstSentinel = this->_firstSentinel;
				newNode->lastSentinel = this->_lastSentinel;
				this->_size++;
				return(newNode);
			}

			void	_deleteNode(node_pointer toDelete)
			{
				this->_alloc.destroy(toDelete);
				this->_alloc.deallocate(toDelete, 1);
				this->_size--;
			}

			node_pointer	_selectDeleteNode (node_pointer root)
			{
				node_pointer	temp;
		
				if (root->left == NULL || root->right == NULL)
				{
					temp = root->left ? root->left : root->right;
					if (temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
						root->swap(temp);
					this->_deleteNode(temp);
					return (root);
				}
				else
				{
					temp = this->_minValueNode(root->right);
					root->swap(temp);
					temp->right = _deleteFromTree(temp->right, root->data);
					return (temp);
				}
			}

			node_pointer _deleteFromTree (node_pointer root, const value_type& value)
			{
				if (root == NULL)
					return root;
				std::cout << "print 1" << std::endl;
				if (this->_valueCompare(value, root->data))
					root->left = this->_deleteFromTree(root->left, value);
				else if (this->_valueCompare(root->data, value))
					root->right = this->_deleteFromTree(root->right, value);
				else
					root = this->_selectDeleteNode(root);
				std::cout << "print 2" << std::endl;
				if (root == NULL)
					return (root);
				this->_updateHeight(root);
				return this->_balanceForDeletion(root);
			}

			node_pointer	_clearTree(node_pointer root)
			{
				if (root->left != NULL)
					root->left = this->_clearTree(root->left);
				if (root->right != NULL)
					root->right = this->_clearTree(root->right);;
				return (this->_selectDeleteNode(root)); 
			}

			int _height (node_pointer N)
			{
				if (N == NULL)
					return (0);
				return (N->height);
			}

			int	_getBalance (node_pointer N)
			{

				if (N == NULL)
					return 0;
				return this->_height(N->left) - this->_height(N->right);
			}

			node_pointer	_minValueNode(node_pointer N)
			{
				node_pointer	current = N;
				while (current->left != NULL)
					current = current->left;
				return current;
			}

			void	_updateHeight (node_pointer	N)
			{
				N->height = max(this->_height(N->left), this->_height(N->right)) + 1;
			}

			void	_updateSentinals()
			{
				this->_firstSentinel->parent = this->_root;
				this->_lastSentinel->parent = this->_root;
			}

			void	_setSentinelInfoConstruct()
			{

				this->_firstSentinel->firstSentinel = this->_firstSentinel;
				this->_firstSentinel->lastSentinel = this->_lastSentinel;
				this->_lastSentinel->firstSentinel = this->_firstSentinel;
				this->_lastSentinel->lastSentinel = this->_lastSentinel;
				this->_firstSentinel->parent = this->_root;
				this->_lastSentinel->parent = this->_root;
			}

			void	_createSentinels()
			{
				node_pointer first = this->_alloc.allocate(1);
				this->_alloc.construct(first, value_type());
				this->_firstSentinel = first;

				node_pointer last = this->_alloc.allocate(1);
				this->_alloc.construct(last, value_type());
				this->_lastSentinel = last;
			}

			void	_destroySentinels()
			{
				this->_deleteNode(this->_firstSentinel);
				this->_deleteNode(this->_lastSentinel);
			}
		public:

			///////////////
			// Iterators //
			///////////////

			iterator begin ()
			{
				return iterator(this->_firstSentinel->_next());
			}

			const_iterator begin () const
			{
				return const_iterator(this->_firstSentinel->_next());
			}
			
			iterator end ()
			{
				return iterator(this->_lastSentinel);
			}

			const_iterator end () const
			{
				return const_iterator(this->_lastSentinel);
			}
			
			reverse_iterator rbegin()
			{
				return reverse_iterator(this->_lastSentinel->_prev());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(this->_lastSentinel->_prev());
			}
			
			reverse_iterator rend()
			{
				return reverse_iterator(this->_firstSentinel);
			}
			
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(this->_firstSentinel);
			}

			//////////////
			// Capacity //
			//////////////
			bool		empty () const { return (this->_size == 0); }
			size_type	size () const { return this->_size; }
			size_type	max_size () const { return this->_alloc.max_size(); }

			/////////////////////
			// Element acccess //
			/////////////////////
			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			}

			void preOrder (node_pointer root) const
			{
				if(root != NULL)
				{
					std::cout << root->data.first << " ";
					preOrder(root->left);
					preOrder(root->right);
				}
			}

			void	printTree () const
			{
				this->preOrder(this->_root);
				std::cout << std::endl;
			}

			///////////////
			// modifiers //
			///////////////
			ft::pair<iterator,bool>	insert (const value_type& val)
			{
				size_type oldsize = this->_size;
				this->_root = _insertNewNode(this->_root, val, NULL);
				this->_updateSentinals();
				iterator itr = find(val.first);
				return (ft::make_pair(itr, this->_size > oldsize));
			}

			iterator	insert (iterator position, const value_type& val)
			{
				(void)position;
				ft::pair<iterator, bool> ret = insert(val);
				return ret.first;
			}

			template <class InputIterator>
			typename ft::enable_if<ft::is_inputiterator<InputIterator>::value, void>::type	insert (InputIterator first, InputIterator last)
			{
				for(; first != last; first++)
					insert(*first);
			}

			void		erase (iterator position)
			{
				this->_root = this->_deleteFromTree(this->_root, *position);
				std::cout << "klaar" << std::endl;
			}

			size_type	erase (const key_type& k)
			{
				iterator itr = find(k);
				if (itr == this->end())
					return (0);
				this->erase(itr);
				return (1);
			}
			
			void		erase (iterator first, iterator last)
			{
				iterator temp;
				while (first != last)
				{
					temp = first;
					std::cout << "begin iterator" << std::endl;
					first++;
					std::cout << "node to delete: " << first->first << std::endl;
					this->erase(temp);
				}
			}

			void	_updateTreeToSentinels (node_pointer root, node_pointer first, node_pointer last)
			{
				if (root->left)
					_updateTreeToSentinels(root->left, first, last);
				if (root->right)
					_updateTreeToSentinels(root->right, first, last);
				root->firstSentinel = first;
				root->lastSentinel = last;
			}

			void	swap (map& x)
			{
				ft::swap(this->_root, x._root);
				this->_updateSentinals();
				x._updateSentinals();
				if (this->_root)
					this->_updateTreeToSentinels(this->_firstSentinel, this->_lastSentinel);
				if (x._root)
					x._updateTreeToSentinels(x._firstSentinel, x._lastSentinel);
				ft::swap(this->_size, x._size);
				ft::swap(this->_compare, x._compare);
				ft::swap(this->_valueCompare, x._valueCompare);
				ft::swap(this->_alloc, x._alloc);
			}

			void	clear ()
			{
				if (this->_root != NULL)
					_clearTree(this->_root);
				this->_root = NULL;
				this->_updateSentinals();
			}

			///////////////
			// observers //
			///////////////

			key_compare key_comp () const
			{
				return this->_compare;
			}

			value_compare value_comp () const
			{
				return (this->_valueCompare);
			}

			////////////////
			// operations //
			////////////////

			size_type	count (const key_type& k) const
			{
				if (this->find(k) == this->end())
					return (0);
				return (1);
			}

			const_iterator	_find (node_pointer node, const key_type& k) const
			{
				if (node == NULL)
					return this->end();
				if (this->_compare(k, node->data.first))
					return _find(node->left, k);
				if (this->_compare(node->data.first, k))
					return _find(node->right, k);
				return iterator(node);
			}

			iterator	find (const key_type& k)
			{
				if (this->_root == NULL)
					return this->end();
				return (this->_find(this->_root, k).get_ptr());
			}

			const_iterator	find (const key_type& k) const
			{
				if (this->_root == NULL)
					return this->end();
				return (this->_find(this->_root, k));
			}

			iterator	lower_bound (const key_type& k)
			{
				iterator itr = this->begin();
				while (itr != this->end() && this->_compare(itr->first, k) == true)
					itr++;
				return (itr);
			}
			const_iterator	lower_bound (const key_type& k) const
			{
				const_iterator c_itr = this->begin();
				while (c_itr != this->end() && this->_compare(c_itr->first, k) == true)
					c_itr++;
				return (c_itr);
			}

			iterator	upper_bound (const key_type& k)
			{
				iterator itr = this->begin();
				while (itr != this->end() && this->_compare(k, itr->first) == false)
					itr++;
				return (itr);
			}

			const_iterator	upper_bound (const key_type& k) const
			{
				const_iterator c_itr = this->begin();
				while (c_itr != this->end() && this->_compare(k, c_itr->first) == false)
					c_itr++;
				return (c_itr);
			}

			ft::pair<iterator,iterator>	equal_range (const key_type& k)
			{
				return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
			}

			ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
			{
				return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
			}

			///////////////
			// Allocator //
			///////////////

			allocator_type	get_allocator (void) const {return this->_alloc;}

			/////////////////////////
			// assignment operator //
			/////////////////////////

			map& operator= (const map& x)
			{
				if (this->_root != NULL)
					this->clear();
				this->_compare = x._compare;
				this->_valueCompare = x._valueCompare;
				this->insert(x.begin(), x.end());
				return *this;
			}

			//////////////////
			// constructors //
			//////////////////
			map (const map& x) : _root(NULL), _size(0), _compare(x._compare),  _valueCompare(x._compare), _alloc(x._alloc)
			{
				this->_createSentinels();
				this->_setSentinelInfoConstruct();
				*this = x;
				return ;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<ft::is_inputiterator<InputIterator>::value>::type* = NULL) : _root(NULL), _size(0), _compare(comp), _valueCompare(comp), _alloc(alloc)
			{
				this->_createSentinels();
				this->_setSentinelInfoConstruct();
				this->insert(first, last);
			}

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _size(0), _compare(comp), _valueCompare(comp), _alloc(alloc)
			{
				this->_createSentinels();
				this->_setSentinelInfoConstruct();
				return ;
			}

			/////////////////
			// destructors //
			/////////////////

			~map ()
			{
				this->clear();
				this->_destroySentinels();
				return ;
			}
		
	}; //end class map

		///////////////////////////
		// operator declerations //
		///////////////////////////
		template<class Key, class T, class Compare, class Alloc>
		bool	operator== (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
		{
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template<class Key, class T, class Compare, class Alloc>
		bool	operator!= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

		template<class Key, class T, class Compare, class Alloc>
		bool	operator< (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template<class Key, class T, class Compare, class Alloc>
		bool	operator<= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
		{
			return !(rhs < lhs);
		}

		template<class Key, class T, class Compare, class Alloc>
		bool	operator> (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
		{
			return (rhs < lhs);
		}

		template<class Key, class T, class Compare, class Alloc>
		bool	operator>= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
		{
			return !(lhs < rhs);
		}

} // end namespace

#endif
