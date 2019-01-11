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
    	void createNode(int value)
    	{
    		node *temp = new node;
    		temp -> data = value;
    		temp -> next = NULL;

    		if (head == NULL)
    		{
    			head = temp;
    			tail = temp;
    			temp = NULL;
    		}
    		else
    		{
    			tail -> next = temp;
    			tail = temp;
    		}
    	}
    	
    	int getData(int nodeNumber)
    	{
    		return 1;
    	}

    	int getSize()
    	{
    		return 3;
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
    	list listA;
    	list listB;
    	list intersection;

    	listA.createNode(1);
    	listA.createNode(2);
    	listA.createNode(3);
    	listA.createNode(4);

		listB.createNode(3);
    	listB.createNode(5);
    	listB.createNode(6);
    	listB.createNode(4); 

    	listA.print();
    	listB.print();

    	node *listAHead = listA.head; //save the head of list A
    	node *listBHead = listB.head; //save the head of list B

    	while(listA.head != NULL)
    	{
    		listB.head = listBHead;
    		
    		while(listB.head != NULL)
    		{
    			
    			if(listB.head -> data == listA.head -> data)
    				intersection.createNode(listA.head -> data);
    			


    			cout << " list B  " << listB.head -> data << endl;
    			listB.head = listB.head -> next;
    		}
    		cout << " list A  " << listA.head -> data << endl;
    		listA.head = listA.head -> next;
    	}   	


    	// for(int i = 0; i < listA.getSize(); i++)
    	// {
    		
    	// 	for(int j = 0; j < listB.getSize(); j++)
    	// 	{

    	// 	}
    	// }

    	//restoring heads of list A and B
    	listA.head = listAHead;
    	listB.head = listBHead;

    	intersection.print();



        return 0;	
    }








