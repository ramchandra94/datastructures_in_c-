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

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    
    if(head == NULL){
        return head;
    }
    
    if(pos == 0){
        Node * temp = head->next;
        delete head;
        return temp;
    }
    
    Node * newTail = deleteNodeRec(head -> next, pos - 1);
    
    head -> next = newTail;
    
    return head;
}