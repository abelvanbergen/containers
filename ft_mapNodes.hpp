/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapNodes.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 09:21:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2021/10/21 11:07:02 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPNODES_HPP
# define FT_MAPNODES_HPP

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
			mapNode*	_next()
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

			mapNode*	_prev()
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

		public:
			///////////////////////
			// operator overload //
			///////////////////////

			// a++
			mapNode	operator++(int)
			{
				mapNode old = *this;

				this->_next();
				return (old);
			}
			// ++a
			mapNode&	operator++()
			{
				this->_next();
				return *this;
			}

			// a--
			mapNode	operator--(int)
			{
				mapNode old = *this;

				this->prev();
				return (old);
			}
			// --a
			mapNode&	operator--()
			{
				this->prev();
				return *this;
			}

			/////////////////////////
			// assignment operator //
			/////////////////////////
			mapNode&	operator= (const mapNode& srcs)
			{
				this->data = srcs.data;
				this->left = srcs.left;
				this->right = srcs.right;
				this->parent = srcs.parent;
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
