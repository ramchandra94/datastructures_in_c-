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

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    
    if(head == NULL || n == 0){
        return head;
    }
    
    Node *p1 = head;
    Node *p2 = head;
    
    while(p2 != NULL && n > 0){
        p2 = p2 -> next;
        n--;
    }
    
    if(p2 != NULL){
        while(p2 -> next != NULL){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        Node * newHead = p1 -> next;
        
        p1 -> next = NULL;
        p2 -> next = head;
        return newHead;
    }
    
    return head;
}