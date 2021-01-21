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

int findNodeRec(Node *head, int n)
{
	//Write your code here
    int idx = 0;
    while(head != NULL){
        if(head -> data == n){
            return idx;
        }
        head = head -> next;
        idx++;
    }
    
    return -1;
}