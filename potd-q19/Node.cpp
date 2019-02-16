#include "Node.h"
#include <iostream>

/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    // your code here
   // Node *final = first;
   // std::cout << __LINE__ << std::endl;

    Node *firstTemp = NULL;
    Node *dataNode = new Node();
   // std::cout << __LINE__ << std::endl;    
    dataNode->data_ = data;
  //  std::cout << __LINE__ << std::endl;    
    dataNode->next_ = NULL;
    firstTemp = first->next_;
    //std::cout << __LINE__ << std::endl;
    std::cout << data << std::endl;
    std::cout << first->data_ << std::endl;
    //std::cout << first->next_->data_ << std::endl;
    if(first == NULL)
    {
        first = dataNode;
        std::cout << __LINE__ << std::endl;          
        return first;
        std::cout << __LINE__ << std::endl;          
    }
    if(first->next_ != NULL)
    {
        //if(first->data_ <= data && first->next_->data_ >= data)
        if(data == first->data_)
            return first;

        if(data < first->data_)
        {
            std::cout << __LINE__ << std::endl;            
            dataNode->next_ = firstTemp;
            first->next_ = dataNode;
            std::cout << __LINE__ << std::endl;
            return first;
        }
        else
        {
            std::cout << __LINE__ << std::endl;
            insertSorted(first->next_, data);
            std::cout << __LINE__ << std::endl;
        }
    }
    else
    {
            if(data == first->data_)
                return first;

            std::cout << __LINE__ << std::endl;
            first->next_ = dataNode;
            std::cout << __LINE__ << std::endl;
            return first;        
    }

    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = new Node();
    out->data_ = first->data_;
    out->next_ = NULL;
  //  Node firstTemp = first;
    //Node secondTemp = second;

    // out = insertSorted(first, 2);
    // out = insertSorted(first, 3);
    // out = insertSorted(first, 4);        
    //while (first != NULL) {
        // your code here
        // hint: call insertSorted and update l1
       while(first != NULL)
       {
        std::cout << __LINE__ << std::endl;
        out = insertSorted(out, first->data_);        
        first = first->next_;
       }

       while(second != NULL)
       {
        std::cout << __LINE__ << std::endl;
        out = insertSorted(out, second->data_);        
        second = second->next_;
       }
   // }

  //  while (second != NULL) {
        // your code here
   // }

    return out;
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
