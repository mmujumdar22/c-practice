    #include <iostream>
    #include <fstream>
    using namespace std;

    struct node
    {
    	int data;
    	node *next;
    	node *prev;
    };


    class list
    {
    private:

    public: 
        node *head, *tail;        
        list()
        {
            head = NULL;
            tail = NULL;
        }
        void createnode(int value)
        {
            node *temp = new node;
            temp -> data = value;
            temp -> prev = NULL;
            temp -> next = head;

            if(head != NULL)
            {
                head->prev = temp;
            }
            // else
            // {
            //     tail->next = temp;
            //     tail = temp;
            // }
            head = temp;
        }
    
        void print()
        {
            node *temp = new node;
            temp = head;

            while(temp != NULL)
            {
                cout << temp -> data << endl;
                temp = temp -> next;
            }
        }
    };   

	int main() 
	{
        list list;


        list.createnode(1);
        list.createnode(2);
        list.createnode(3);
        list.createnode(4);

        list.print();

        node *A = list.head -> next;
        node *B = list.head -> next -> next;

        list.head -> next = B;
        B -> prev = list.head;

        A -> next = B -> next;
        B -> next -> prev = A;

        B -> next = A;
        A -> prev = B;

        // A -> next = list.head -> next -> next -> next;
        // list.head -> next -> next -> next -> prev = A;
        
        list.print();






        return 0;

	}         