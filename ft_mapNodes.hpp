/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapNodes.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 09:21:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/07 19:33:01 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPNODES_HPP
# define FT_MAPNODES_HPP

# include "ft_utils.hpp"

namespace ft {
	template <class T>
	struct mapNode
	{
		private:
			typedef mapNode<T>											node;
			typedef node*												node_pointer;

		public:
			T				data;
			node_pointer	left;
			node_pointer	right;
			node_pointer	parent;
			node_pointer	firstSentinel;
			node_pointer	lastSentinel;
			int				height;

		public:
			node_pointer	_next () const
			{
				//make a temp so you can look trough the tree
				node_pointer temp = const_cast<node_pointer>(this);
				//if you are already at the end
				if (temp == temp->lastSentinel)
					return (NULL);
				//if you are at the beginning
				if (temp == temp->firstSentinel)
				{
					//if the tree is empty
					if (temp->parent == NULL)
						return(temp->lastSentinel);
					temp = temp->parent;
					while (temp->left != NULL)
						temp = temp->left;
				}
				//if you can go right
				else if (temp->right != NULL)
				{
					temp = temp->right;
					while (temp->left != NULL)
						temp = temp->left;
				}
				//no right child to go to, so you have to go up.
				//This means it can also be the "last" node and then you have to to the lastSentinel
				else
				{
					while(temp->parent != NULL && temp->parent->right == temp)
						temp = temp->parent;
					temp = temp->parent;
					if (temp == NULL)
						return (this->lastSentinel);
				}
				return (temp);
			}

			node_pointer	_prev () const
			{
				//make a temp so you cab look trough the tree
				node_pointer temp = const_cast<node_pointer>(this);
				//if you are already at the begin
				if (temp == temp->firstSentinel)
					return (NULL);
				//if you are at the end
				if (temp == temp->lastSentinel)
				{
					//if the tree is empty
					if (temp->parent == NULL)
						return(temp->firstSentinel);
					temp = temp->parent;
					while (temp->left != NULL)
						temp = temp->left;
				}
				//if ypu still have a left child to go to
				if (temp->left != NULL)
				{
					temp = temp->left;
					while (temp->right != NULL)
						temp = temp->right;
				}
				//no left child to go to, so you have to go up.
				//This means it can also be the "first" node and then you have to to the firstSentinel
				else
				{
					while(temp->parent != NULL && temp->parent->left == temp)
						temp = temp->parent;
					temp = temp->parent;
					if (temp == NULL)
						return (this->firstSentinel);
				}
				return (temp);
			}

			////////////////////
			// swap functions //
			////////////////////
		private:
			void	 _parentSwap(node_pointer x)
			{
				node_pointer	xParent;

				xParent = x->parent;
				if (this->parent != NULL)
				{
					if (this->parent->left == this)
						this->parent->left = x;
					else
						this->parent->right = x;
				}
				x->parent = this->parent;
				if (xParent != NULL)
				{
					if (xParent->left == x)
						xParent->left = this;
					else
						xParent->right = this;
				}
				this->parent = NULL;
			}

			void	_leftChildSwap(node_pointer x)
			{
				node_pointer	xLeft;

				xLeft = x->left;
				if (this->left != NULL)
					this->left->parent = x;
				x->left = this->parent;
				if (xLeft != NULL)
					xLeft->parent = this;
				this->parent = NULL;
			}

			void	_rightChildSwap(node_pointer x)
			{
				node_pointer	xRight;

				xRight = x->right;
				if (this->right != NULL)
					this->right->parent = x;
				x->right = this->parent;
				if (xRight != NULL)
					xRight->parent = this;
				this->parent = NULL;
			}

		public:
			void	swap (node_pointer x)
			{
				this->_parentSwap(x);
				this->_leftChildSwap(x);
				this->_rightChildSwap(x);
				ft::swap(this->height, x->height);
			}
			
		public:
			/////////////////////////
			// assignment operator //
			/////////////////////////
			mapNode&	operator= (const mapNode& srcs)
			{
				this->data.second = srcs.data.second;
				this->left = srcs.left;
				this->right = srcs.right;
				this->parent = srcs.parent;
				this->firstSentinel = srcs.firstSentinel;
				this->lastSentinel = srcs.lastSentinel;
				this->height = srcs.height;
				return *this;
			}

			//////////////////
			// constructors //
			//////////////////

			mapNode (const mapNode& srcs)
			{
				*this = srcs;
				return ;
			}

			mapNode (const T& data = T()) : data(data), left(NULL), right(NULL), parent(NULL), firstSentinel(NULL), lastSentinel(NULL), height(1)
			{
				return ;
			}

			/////////////////
			// destructors //
			/////////////////

			~mapNode() {return ;}

	};
}

#endif
