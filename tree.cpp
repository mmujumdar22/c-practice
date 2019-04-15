#ifndef TREE_CPP
#define TREE_CPP
#include <iostream>
#include "tree.h"

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
	// TODO: your code here
	// curr_ = s.peek();
	// while(root != NULL)
	// {
	// 	s.push(root);
	// 	curr_ = root;
	// 	root = root->right_;
	// }
	Node *cur = root;
	while (root != NULL || s.empty() != true)
	{	/* code */
		while(root != NULL)
		{
			std::cout << *cur->data_ << std::endl;
			std::cout << *cur->right_->data_ << std::endl;
			s.push(root);
			root = root -> right_;
		//*this = *this -> right_;
		}

		q.push(s.top());
		root = s.top();
		s.pop();
		//return *this;
		root = root ->left_;
	}
}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
	// TODO: your code here

	//temp = q;

	while(curr_!= q.front())
	{
			// temp.dequeue();
		//	std::cout << *curr_->data_ << std::endl;
			q.pop();
			// curr_ = temp.front();
			// return *this;
	}

	curr_ = q.front();
	return *this;
	//Node *temp = this;
	// if(curr_ == NULL)
	// {
	// 	return Iterator(NULL);
	// }
	// while (curr_ != NULL || s.empty() != true)
	// {	/* code */
	// 	while(curr_ != NULL)
	// 	{
	// 		s.push(curr_);
	// 		curr_ = curr_ -> right_;
	// 	//*this = *this -> right_;
	// 	}
	//
	// 	enqueue(s.top());
	// 	// curr_ = s.top();
	// 	s.pop();
	// 	//return *this;
	// 	curr_ = curr_ ->left_;
	// }
//	s.push(curr_);
	// if(s.empty() == false)
	// {
	// 	curr_ =s.top();
	// 	s.pop();
	//
	// }
	// curr_ = curr_ ->left_;
	// while(curr_ != NULL)
	// {
	// 	s.push(curr_);
	// 	curr_ = curr_ ->right_;
	// }
	// if(!traversal->empty())
	// {
	// 	curr_ = traversal->pop();
	// 	traversal->add(curr_);
	// 	curr_ = traversal.top();
	// }
//	return *this;
	//return iterator(curr_);
}

template <class T>
T Tree<T>::Iterator::operator*() const {
	// TODO: your code here
	return curr_->data_; // remove this line
}



/*******************
 ** PROVIDED CODE **
 *******************/
template <class T>
bool Tree<T>::Iterator::operator!=(const Tree<T>::Iterator &other) {
	return !(curr_ == other.curr_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(root_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(NULL);
}

#endif
