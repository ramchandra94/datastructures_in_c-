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

bool isPalindrome(Node *head)
{
    //Write your code here
    
    if(head == NULL || head -> next == NULL){
        return true;
    }
    
    Node *slow = head;
    Node *fast = head;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast->next->next;
    }
    
    Node * prev = NULL;
    while(slow != NULL){
        Node * temp = slow -> next;
        slow -> next = prev;
        prev = slow;
        slow = temp;
    }

    while(prev != NULL){
        if(head->data != prev->data){
        
            return false;
        }
        head = head -> next;
        prev = prev -> next;
    }
    
    return true;
}