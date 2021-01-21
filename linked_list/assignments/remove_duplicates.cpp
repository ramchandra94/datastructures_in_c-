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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head == NULL){
        return head;
    }
    
    Node *killer = head;
    
    while(killer != NULL && killer -> next != NULL){
        
        while(killer -> next != NULL && killer -> data == killer -> next -> data){
            Node *killIt = killer -> next;
            killer -> next = killer -> next -> next;
            delete killIt;
        }
        
        killer = killer -> next;
    }
    
    return head;
}