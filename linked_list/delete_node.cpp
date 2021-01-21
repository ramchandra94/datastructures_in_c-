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

Node *deleteNode(Node *head, int pos)
{
    //Write your code here
    if(head == NULL){
        return head;
    }
    Node * tempHead = head;
    int count = 0;
    if(pos == 0){
        head = head -> next;
        delete tempHead;
        return head;
    }
    
    while(tempHead != NULL && count < pos - 1){
        tempHead = tempHead -> next;
        count++;
    }
    
    if(tempHead != NULL && tempHead -> next != NULL){
        Node * tempDel = tempHead -> next;
        
        tempHead -> next = tempHead -> next -> next;
        
        delete tempDel;
    }
    
    return head;
    
}