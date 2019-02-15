#include "Node.h"
#include <iostream>


void mergeList(Node *first, Node *second) {

	//std::cout << __LINE__ << std::endl;

	if(first == NULL && second == NULL)
		return;
		//std::cout << __LINE__ << std::endl;
	if(first != NULL || second != NULL)
	{
		//std::cout << __LINE__ << std::endl;	
		Node *firstTemp = NULL;
		Node *secondTemp = NULL;
		//std::cout << __LINE__ << std::endl;
		if(first != NULL && first->next_ != NULL)
		{
			firstTemp = first->next_;
			if(second != NULL)
				first->next_ = second;
		}
		else if(first != NULL)
		{
			first->next_ = second;
			return;
		}
		//std::cout << __LINE__ << std::endl;		
		if(second != NULL && second->next_ != NULL)
		{
			secondTemp = second->next_;
			if(first != NULL)
				second->next_ = firstTemp;
		}
		// else if(second != NULL)
		// {
		// 	first->next_ = second;
		// }
		//std::cout << __LINE__ << std::endl;		

		//std::cout << __LINE__ << std::endl;
		//second->next_ = firstTemp;
		//std::cout << second->next_->data_ << " " << secondTemp->next_->data_<< std::endl;
		mergeList(firstTemp, secondTemp);
		//std::cout << __LINE__ << std::endl;
	}
	else
		return;	
  // your code here!
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
