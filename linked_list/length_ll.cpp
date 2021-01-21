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

int length(Node *head)
{
    //Write your code here
    int ll_length = 0;
	
    while(head != NULL){
        ll_length++;
        head = head -> next;
    }
    
    return ll_length;
}
