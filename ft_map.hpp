/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 09:13:43 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/10/22 14:16:42 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <memory>
# include <exception>

#include "ft_bidirectional_iterator.hpp"
#include "ft_mapNodes.hpp"
#include "ft_pair.hpp"
# include "ft_utils.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		//////////////
		// typedefs //
		//////////////
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef	const value_type*								const_pointer;
			typedef bidirectional_iterator<value_type>				iterator;
			typedef bidirectional_iterator<const value_type>		const_iterator;
			typedef std::size_t										size_type;

		private:
			typedef mapNode<value_type>								node;
			typedef node*											node_pointer;
			typedef typename Alloc::template rebind<node>::other	node_alloc;

		private:
			node					_firstSentinel;
			node					_lastSentinel;
			node_pointer			_root;
			size_type				_size;
			key_compare				_compare;
			node_alloc				_alloc;

			///////////////////
			// BST functions //
			///////////////////

			node_pointer	rightRotate (node_pointer y)
			{
				node_pointer x = y->left;
				node_pointer T2 = y->right;

				x->parent = y->parent;
				y->parent = x;
				if (T2)
					T2->parent = y;
				x->right = y;
				y->left = T2;

				_updateHeight(y);
				_updateHeight(x);

				return x;
			}

			node_pointer	leftRotate (node_pointer x)
			{
				node_pointer y = x->right;
				node_pointer T2 = x->left;

				y->parent = x->parent;
				x->parent = y;
				if (T2)
					T2->parent = x;
				y->left = x;
				x->right = T2;

				_updateHeight(x);
				_updateHeight(y);
				return y;
			}

			node_pointer	_balance(node_pointer root)
			{

			}

			node_pointer	_insertNewNode(node_pointer root, const value_type& value)
			{
				if (!root)
					return (this->_newNode());
				if (value_type < root->data) //dit moet de compare functie worden; Ook bij volgende vergelijkingen
					root->left = _insertNewNode(root->left, value);
				else if (root->data < newNode->data)
					root->right = _insertNewNode(root->right, value);
				else
					return (root);
				_updateHeight(root);

				int balance = getBalance(root);
				if (balance > 1 && value < root->left->data) //Left Left Case
					return rightRotate(root);
				if (balance < -1 && value > root->right->data) //Right Left Case
					return leftRotate(root);
				if (balance > 1 && value > root->left->data) //Left Right Case
				{
					root->left = leftRotate(root->left);
					return rightRotate(root);
				}
				if (balance < -1 && value < root->right->data) //Right Left Case
				{
					root->right = rightRotate(root);
					return leftRotate(root);
				}
				return root;
			}

			node_pointer	_newNode (const value_type& value, node_pointer parent)
			{
				node_pointer newNode = this->_alloc.allocate(1);

				this->_alloc.construct(newNode, value);
				newNode->parent = parent;
				newNode->firstSentinel = &this->_firstSentinel;
				newNode->lastSentinel = &this->_lastSentinel;
				this->_size++;
				return(newNode);
			}

			void	_deleteNode(node_pointer toDelete)
			{
				this->_alloc.destroy(toDelete);
				this->_alloc.deallocate(toDelete, 1);
				this->_size--;
			}

			void	_clearTree(node_pointer root)
			{
				if (root->left != NULL)
				{
					this->_clearTree(root->left);
				}
				if (root->right != NULL)
					this->_clearTree(root->right);
				this->_deleteNode(root);
				root = NULL;
			}

			int height (node_pointer N)
			{
				if (N == NULL)
					return (0);
				return (N->height);
			}

			int	getBalance (node_pointer N)
			{

				if (N == NULL)
					return 0;
				return height(N->left) - height(N->right);
			}

			void	_updateHeight (node_pointer	N)
			{
				N->height = max(height(N->left), height(N->right)) + 1;
			}
		public:

			///////////////
			// Iterators //
			///////////////

			iterator begin() {return iterator(this->_firstSentinel->parent); }
			const_iterator begin() const {return iterator(this->_firstSentinel->parent); }
			iterator end() {return iterator(this->_lastSentinel); }
			const_iterator end() const {return iterator(this->_lastSentinel); }
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			//////////////
			// Capacity //
			//////////////
			bool		empty() const { return (this->_size == 0); }
			size_type	size() const { return this->_size; }
			size_type	max_size() const { return this->_alloc.max_size(); }

			/////////////////////
			// Element acccess //
			/////////////////////
			mapped_type& operator[] (const key_type& k)
			{
				(*((this->insert(make_pair(k,mapped_type()))).first)).second;
			}

			///////////////
			// modifiers //
			///////////////
			pair<iterator,bool>	insert (const value_type& val)
			{
				size_type oldsize = this->_size;
				this->_root = insertNewNode(this->_root, val);
				iterator itr = find(va.first);
				return (make_pair(itr, this->_size > oldsize));
			}

			iterator			insert (iterator position, const value_type& val)
			{
				this->_root = insertNewNode(this->_root, val);
				iterator itr = find(va.first);
				return itr;
			}

			template <class InputIterator>
			void				insert (InputIterator first, InputIterator last)
			{
				for(; first != last; first++)
					insert(first.data);
			}

			// void		erase (iterator position);
			// size_type	erase (const key_type& k);
			// void		erase (iterator first, iterator last);

			// void	swap (map& x);

			void	clear()
			{
				_clearTree(this->_root);
			}

			key_type	test()
			{
				return (this->_root->data.first);
			}

			///////////////
			// observers //
			///////////////

			key_compare key_comp() const;

			// value_compare value_comp() const;

			////////////////
			// operations //
			////////////////

			size_type	count (const key_type& k) const;

			iterator	_find (node_pointer node, const key_type& k) // moet evrvangen worden door de varianten met iterators
			{
				if (node->data.first == k)
					return iterator(node);
				if (node->left == NULL && k < node->data.first)
					return this->end();
				if (node->right == NULL && k > node->data.first)
					return this->end();
				if (k < node->data.first)
					_find(node->left, k);
				else
					_find(node->right, k);
				return this->end();
			}

			iterator	find (const key_type& k)
			{
				if (this->_root == NULL)
					return this->end();
				return (this->_find(this->_root, k));
			}

			const_iterator	find (const key_type& k) const
			{
				if (this->_root == NULL)
					return this->end();
				return (this->_find(this->_root, k));
			}

			// iterator	lower_bound (const key_type& k);
			// const_iterator	lower_bound (const key_type& k) const;

			// iterator	upper_bound (const key_type& k);
			// const_iterator	upper_bound (const key_type& k) const;

			// pair<iterator,iterator>	equal_range (const key_type& k);
			// pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;

			///////////////
			// Allocator //
			///////////////

			allocator_type	get_allocator (void) const {return this->_alloc;}

			/////////////////////////
			// assignment operator //
			/////////////////////////

			map& operator= (const map& x)
			{
				if (this->root != NULL)
					this->clear();
				this->_compare = x._compare;
				this->_alloc = x._alloc;
				this->_copyTree(x);
			}

			//////////////////
			// constructors //
			//////////////////
			map (const map& x) : _root(NULL), _size(0), _compare(x.compare), _alloc(x._alloc)
			{
				*this = x;
				return ;
			}

			// template <class InputIterator>
			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _compare(comp), _alloc(alloc)
			{
				this->_firstSentinel.firstSentinel = &this->_firstSentinel;
				this->_firstSentinel.lastSentinel = & this->_lastSentinel;
				this->_lastSentinel.firstSentinel = &this->_firstSentinel;
				this->_lastSentinel.lastSentinel = & this->_lastSentinel;
				this->_firstSentinel.parent = this->_root;
				this->_lastSentinel.parent = this->_root;
			}

			/////////////////
			// destructors //
			/////////////////

			~map()
			{
				return ;
			}

	}; //end class map
} // end namespace

#endif
