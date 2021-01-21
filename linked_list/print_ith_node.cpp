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

void printIthNode(Node *head, int i)
{
    //Write your code here
    int idx = 0;
    while(head != NULL && head->data != -1 && idx < i){
        head = head -> next;
        idx++;
    }
    
    if(head != NULL && idx == i){
        cout << head->data;
    }
    
    cout << endl;
}