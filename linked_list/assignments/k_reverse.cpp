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

Node *kReverse(Node *head, int k)
{
	//Write your code here
    
    if(head == NULL || head -> next == NULL || k == 0){
        return head;
    }
    
    Node *myTail = head;
    Node * prev = NULL;
    int count = k;
    while(head != NULL && count > 0){
        Node *temp = head -> next;
        head -> next = prev;
        prev = head;
        head = temp;
        count--;
    }
    
    Node *rightHead = kReverse(head, k);
    myTail -> next = rightHead;
    return prev;
    
}