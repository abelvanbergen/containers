/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapNodes.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 09:21:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/11/10 14:44:02 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPNODES_HPP
# define FT_MAPNODES_HPP

# include "ft_utils.hpp"

namespace ft {
	template <class T>
	struct mapNode
	{
		public:
			T			data;
			mapNode*	left;
			mapNode*	right;
			mapNode*	parent;
			mapNode*	firstSentinel;
			mapNode*	lastSentinel;
			int			height;

		private:
			typedef mapNode<T>											node;
			typedef node*												node_pointer;

		private:
			mapNode*	_next ()
			{
				mapNode* temp;
				if (this == this->lastSentinel)
					return (0);
				if (this == this->firstSentinel)
				{
					temp = this->parent;
					while (temp->left != NULL)
						temp = temp->left;
				}
				else if (this->right != NULL)
				{
					temp = this->right;
					while (temp->left != NULL)
						temp = temp->left;
				}
				else
				{
					temp = this;
					while(temp->parent == NULL && temp->parent->right == temp)
						temp = temp->parent;
					temp = temp->parent;
					if (temp == NULL)
						return (this->lastSentinel);
				}
				return (temp);
			}

			mapNode*	_prev ()
			{
				mapNode* temp;
				if (this == this->firstSentinel)
					return (0);
				if (this == this->lastSentinel)
				{
					temp = this->parent;
					while (temp->left != NULL)
						temp = temp->left;
				}
				if (this->left != NULL)
				{
					temp = this->left;
					while (temp->right != NULL)
						temp = temp->right;
				}
				else
				{
					temp = this;
					while(temp->parent == NULL && temp->parent->left == temp)
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
			void	 _parentSwap(mapNode& x)
			{
				node_pointer	xParent;

				xParent = x.parent;
				if (this->parent != NULL)
				{
					if (this->parent->left == this)
						this->parent->left = &x;
					else
						this->parent->right = &x;
				}
				x.parent = this->parent;
				if (xParent != NULL)
				{
					if (xParent->left == &x)
						xParent->left = this;
					else
						xParent->right = this;
				}
				this->parent = NULL;
			}

			void	_leftChildSwap(mapNode& x)
			{
				node_pointer	xLeft;

				xLeft = x.left;
				if (this->left != NULL)
					this->left->parent = &x;
				x.left = this->parent;
				if (xLeft != NULL)
					xLeft->parent = this;
				this->parent = NULL;
			}

			void	_rightChildSwap(mapNode& x)
			{
				node_pointer	xRight;

				xRight = x.right;
				if (this->right != NULL)
					this->right->parent = &x;
				x.right = this->parent;
				if (xRight != NULL)
					xRight->parent = this;
				this->parent = NULL;
			}

		public:
			void	swap (mapNode& x)
			{
				this->_parentSwap(x);
				this->_leftChildSwap(x);
				this->_rightChildSwap(x);
				ft::swap(this->height, x.height);
			}
			
		public:
			///////////////////////
			// operator overload //
			///////////////////////

			// a++
			mapNode	operator++ (int)
			{
				mapNode old = *this;

				this->_next();
				return (old);
			}
			// ++a
			mapNode&	operator++ ()
			{
				this->_next();
				return *this;
			}

			// a--
			mapNode	operator-- (int)
			{
				mapNode old = *this;

				this->prev();
				return (old);
			}
			// --a
			mapNode&	operator-- ()
			{
				this->prev();
				return *this;
			}

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
