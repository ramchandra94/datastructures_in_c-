/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
void my_swap (Node *node_1, Node *node_2)
{
	int temp = node_1->data;
	node_1->data = node_2 -> data;
	node_2 -> data = temp;
}


Node *bubbleSort(Node *head)
{
	// Write your code here
    
    if(head == NULL){
        return head;
    }
    int swapped;

	Node *lPtr; // left pointer will always point to the start of the list
	Node *rPrt = NULL; // right pointer will always point to the end of the list
	do
	{	
		swapped = 0;
		lPtr = head;
		while(lPtr->next != rPrt)
		{
			if (lPtr->data > lPtr->next->data) 
			{
				my_swap(lPtr, lPtr->next); 
                swapped = 1; 
			}
			lPtr = lPtr->next;
		}
		//as the largest element is at the end of the list, assign that to rPtr as there is no need to
		//check already sorted list
		rPrt = lPtr;

	}while(swapped);
    
    return head;
}