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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    
    if(head1 != NULL && head2 != NULL){
        Node *finalHead = NULL;
    	Node *finalTail = NULL;
        if(head1 -> data <= head2 -> data){
            finalHead = head1;
            finalTail = head1;
            head1 = head1 -> next;
        }
        else{
            finalHead = head2;
            finalTail = head2;
            head2 = head2 -> next;
        }
        
        while(head1 != NULL && head2 != NULL){
            if(head1 -> data <= head2 -> data){
                finalTail -> next = head1;
                finalTail = head1;
                head1 = head1 -> next;
            } else{
                finalTail -> next = head2;
                finalTail = head2;
                head2 = head2 -> next;
            }
        }
        
        if(head1 == NULL){
            finalTail -> next = head2;
            return finalHead;
        }
        
        if(head2 == NULL){
            finalTail -> next = head1;
            return finalHead;
        }
    } 
    else if(head1 != NULL)
    {
        return head1;
    } else
    {
        return head2;
    }
}