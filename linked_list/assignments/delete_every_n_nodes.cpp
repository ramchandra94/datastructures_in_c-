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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head == NULL || N == 0){
        return head;
    }
    
    if(M == 0){
        while(head != NULL){
            Node * prev = head;
            head = head -> next;
            delete prev;
        }
        return head;
    }
    Node * ptr1 = head;
    while(ptr1 != NULL){
        for(int i=0; i < M - 1; i++){
            ptr1 = ptr1 -> next;
            if(ptr1 == NULL){
                return head;
            }
            
        }
        for(int i=0; i < N; i++){
            Node * temp = ptr1 -> next;
            if(temp == NULL){
                return head;
            }
            ptr1 -> next = ptr1 -> next -> next;
            delete temp;
        }
        
        ptr1 = ptr1 -> next;
    }

}