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

Node *evenAfterOdd(Node *head)
{
	//write your code here
    
    if(head == NULL){
        return head;
    }
    
    Node * preEven = head;
    if(preEven -> data % 2 == 0){
        preEven = NULL;
    }
    
    while(preEven != NULL && preEven -> next != NULL && preEven -> next -> data % 2 != 0){
        preEven = preEven -> next;
    }
    
    Node * oddTracker;
    if(preEven == NULL){
        oddTracker = head;
    } else{
        oddTracker = preEven;
    }
    
    while(oddTracker != NULL && oddTracker -> next != NULL){
        if(oddTracker -> next -> data % 2 != 0){
            Node * temp = oddTracker -> next;
            oddTracker -> next = oddTracker -> next -> next;
            if(preEven == NULL){
                temp -> next = head;
                head = temp;
                preEven = head;
            }
            else{
                temp -> next = preEven -> next;
                preEven -> next = temp;
                preEven = temp;
                
            }
        } else{
            oddTracker = oddTracker -> next;
        }
        
    }
    return head;
}