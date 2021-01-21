
/*********************************************************
 
    // Following is the node structure

    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    
        ~Node() {
            if(next) {
                delete next;
            }
        }
    };

*********************************************************/

void deleteAlternateNodes(Node *head) {
    //Write your code here
    Node * ptr1 = head;
    while(ptr1 != NULL && ptr1 -> next != NULL) {
        Node *temp = ptr1 -> next;
        ptr1 -> next = ptr1 -> next -> next;
        ptr1 = ptr1 -> next;
        // delete temp;
    }
}