/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() {
    // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
    // @TODO: graded in MP3.1

    return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
    // @TODO: graded in MP3.1
    return List<T>::ListIterator(tail_->next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
    /// @todo Graded in MP3.1
    ListNode * curr = head_;
    // iterate down the parameter list
    while (curr != NULL)
    {
        curr = head_->next;
        delete head_;
        head_ = curr;
    }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
    // @todo Graded in MP3.1
    ListNode * newNode = new ListNode(ndata);
//  newNode->data_ = ndata;
    length_++;


    if(head_ != NULL)
    {
        newNode->next = head_;
        head_->prev = newNode;
        newNode->prev = NULL;
        head_ = newNode;

    }
    else
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        head_ = newNode;
        tail_ = newNode;

    }

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
    /// @todo Graded in MP3.1

    length_++;

    ListNode* newNode = new ListNode(ndata);
    if(head_!=NULL)
    {
        tail_->next = newNode;
        newNode->prev = tail_;
        newNode->next = NULL;
        tail_ = newNode;
    }
    else
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        head_ = newNode;
        tail_ = newNode;

    }

}
/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
    /// @todo Graded in MP3.1
    ListNode * curr = start;

    for (int i = 0; i < splitPoint && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr != NULL) {
        curr->prev->next = NULL;
        curr->prev = NULL;
    }

    return curr;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall(){
    /// @todo Graded in MP3.1
    // std::cout << __LINE__  << " " << std::endl;
    ListNode *cur = head_;
    ListNode *temp = NULL;
    //  std::cout << __LINE__  << " " << std::endl;
    while (cur->next->next != NULL)
    {
        temp = cur->next;
        // std::cout << __LINE__  << " " << std::endl;
        cur->next = temp->next;

        temp->next->prev = cur;
        //   std::cout << __LINE__  << " " << std::endl;
        tail_->next = temp;
        //   std::cout << __LINE__  << " " << std::endl;
        temp->prev = tail_;
        temp->next = NULL;
        //   std::cout << __LINE__  << " " << std::endl;
        tail_ = temp;
        cur = cur->next;

        temp = NULL;

        //   std::cout << __LINE__  << " " << std::endl;
//     if(temp->next != NULL)
//     {
//         cur = cur->next;
//         //  std::cout << __LINE__  << " " << std::endl;
//         temp = cur->next->next;
//     }
//     else
//         break;
        // std::cout << __LINE__  << " " << std::endl;
    }

}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
    reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
    /// @todo Graded in MP3.2

    ListNode *start = head_;
    ListNode  *end = tail_;

    if(start==end)
        return;

    while(start!=end->next) {
        if (start != startPoint) {
            start=start->next;
        }else{
            break;
        }
    }
    ListNode *newStartPoint = start;
    while(newStartPoint!=end->next) {
        if (newStartPoint != endPoint) {
            newStartPoint=newStartPoint->next;
        }else{
            end = newStartPoint;
            break;
        }
    }

    bool toContinueOrNot = true;
    bool firstExchange = true;
    ListNode * newStart = startPoint;
    ListNode * newEnd = endPoint;
    while(toContinueOrNot){

        //in case of even nodes following condition will tell it is the last exchange
        if (start->next==end && end->prev==start){
            toContinueOrNot = false;
        }

        if(start==end){ //Odd
            break;
        }else{
            // exchange
            ListNode * prevOfStart = start->prev;
            ListNode * nextOfEnd = end->next;
            ListNode * nextOfStart = start->next;
            ListNode * prevOfEnd = end->prev;

            ListNode *temp = end;
            //two to exchange nothing in between
            if(!toContinueOrNot && nextOfEnd!=NULL && prevOfStart!=NULL){
                start->next = nextOfEnd;
                start->prev = temp;
                prevOfStart->next = temp;
                temp->next = start;
                temp->prev = prevOfStart;
                nextOfEnd->prev=start;
                if(firstExchange){
                    newEnd = start;
                    newStart = temp;
                    firstExchange=false;
                }
                break;
            }
//        Two elements list
            if(!toContinueOrNot  && nextOfEnd==NULL && prevOfStart==NULL){
                start->next = NULL;
                start->prev = temp;
                temp->prev = NULL;
                temp->next = start;
                if(firstExchange){
                    newEnd = start;
                    newStart = temp;
                    firstExchange=false;
                }
                break;
            }


            if(temp->prev!=start){
                temp->prev->next = start;
            }else{
                temp->prev->next = nextOfEnd;
            }

            if(prevOfStart!=NULL) {
                prevOfStart->next = temp;
            }

//        if(temp->prev!=start) {
            start->prev = temp->prev;
//        }

            temp->prev = prevOfStart;//can be NULL
//        if(start->next!=temp) {
            temp->next = start->next;
//        }
            //start next has not changed yet
            start->next->prev = temp;
            start->next = nextOfEnd;// can be NULL
            if(nextOfEnd!=NULL){
                nextOfEnd->prev = prevOfStart;
            }

            if(firstExchange){
                newEnd = start;
                newStart = temp;
                firstExchange=false;
            }
            //move to next and continue
            start = nextOfStart;
            end = prevOfEnd;

        }

    }

    startPoint=newStart;
    endPoint = newEnd;
}


/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n){
    /// @todo Graded in MP3.2
    if (head_ != NULL && tail_ != NULL && n > 1) {
        ListNode *curr = head_;
        ListNode *curr_tail = head_;
        int j = 0;

        while (curr_tail != NULL) {
            for (int i = 0; i < n - 1; i++) {
                if (curr_tail->next != NULL) {
                    curr_tail = curr_tail->next;

                }
            }

            ListNode *saveCurrTailnext = curr_tail->next;
            ListNode *saveCurrHeadPrev = curr->prev;
            reverse(curr, curr_tail);
            if (saveCurrHeadPrev != NULL)
                saveCurrHeadPrev->next = curr;
            if (saveCurrTailnext != NULL)
                saveCurrTailnext->prev = curr_tail;


            curr = saveCurrTailnext;
            curr_tail = curr;


        }
        while (head_->prev != NULL)
            head_ = head_->prev;

        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {

    ListNode * curr1=first;
    ListNode * curr2=second;
    ListNode * next_curr1;
    ListNode * next_curr2;
    ListNode * temp;

    if(first!=NULL && second!=NULL)
    {


        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->data<curr2->data||curr1->data==curr2->data)
            {

                next_curr1=curr1->next;//temporary Nodes
                temp=curr2->prev;//temporary Nodes

                if(temp!=NULL)
                    temp->next=curr1;
                curr1->prev=temp;
                curr1->next=curr2;
                curr2->prev=curr1;

                curr1=next_curr1;

            }


            else if(curr2->data<curr1->data)
            {
                next_curr2=curr2->next;//temporary Nodes
                temp=curr1->prev;//temporary Nodes

                if(temp!=NULL)
                    temp->next=curr2;
                curr2->prev=temp;

                curr2->next=curr1;
                curr1->prev=curr2;

                curr2=next_curr2;


            }




        }
        while(first->prev!=NULL)
            first=first->prev;
        return first;


    }
/// @todo Graded in MP3.2

    return NULL; // change me!
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
    /// @todo Graded in MP3.2

    if(chainLength == 1)
        return start;
   // if(chainLength == 0)
     //   return start;
    //if(chainLength != 1 || chainLength != 0)
   // {
        int halfChain = chainLength/2;
        int modChain = chainLength%2;
        int halfMod = halfChain + modChain;

        ListNode *halfWay = split(start, halfChain);

        start = mergesort(start, halfChain);
        halfWay = mergesort(halfWay, halfMod);

        ListNode *final = merge(start, halfWay);
        //return merge(start, halfWay);
        return final;

}