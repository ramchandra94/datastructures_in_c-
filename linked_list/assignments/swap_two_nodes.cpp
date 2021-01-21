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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(head == NULL){
        return head;
    }
    Node * t1 = head;
    Node * t2 = head;
    
    if(i > j){
        int temp = j;
        j = i;
        i = temp;
    }
    
    i = i -1;
    j = j -1;
    while(i > 0){
        t1 = t1 -> next;
        i--;
    }
    Node * p1 = t1 -> next;
    int jump = j - i;
    while(jump > 0){
        t2 = t2 -> next;
        jump--;
    }
    
    
    Node *p2 = t2 -> next;
    
    t1 -> next = p2;
    t2 -> next = p1;

    Node *temp_ptr = p2 -> next;
    
    p2 -> next = p1 -> next;
    
    p1 -> next = temp_ptr;
    
    return head;
}