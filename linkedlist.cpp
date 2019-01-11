    #include <iostream>
    #include <fstream>
    using namespace std;

    struct node
    {
    	int data;
    	node *next;
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
            temp -> next = NULL;

            if(head == NULL)
            {
                head = temp;
                tail = temp;
                temp = NULL;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
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

        // void swapnode(node *first, node *second)
        // {
        //     //node *temp;

        //     //temp = first;
        //     *first->next = *second->next;
        //     *second->next = *first->next;

        //     //temp = nullptr;

        // }
    };



	int main() 
	{
        list list;


        list.createnode(1);
        list.createnode(2);
        list.createnode(3);
        list.createnode(4);

        list.print();

        //list.swapnode((list.head->next),(list.head->next->next));
            node *firstNode = list.head->next;
            node *secondNode = list.head->next->next;
            node *temp = secondNode->next;
            
            secondNode->next = firstNode;            
            firstNode->next = temp;


            list.head->next = secondNode;

           // second->next = first->next;
        list.print();





        return 0;

	}