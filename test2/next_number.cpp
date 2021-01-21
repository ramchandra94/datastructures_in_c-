/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

int carryRecurse(Node * head){
    if(head == NULL){
        return 1;
    }
    int rightCarry = carryRecurse(head -> next);
    if(rightCarry == 1){
        if(head -> data == 9){
            head -> data = 0;
            return 1;
        } else{
            head -> data = head -> data + 1;
            return 0;
        }
    } else {
        return 0;
    }
}
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head == NULL){
        return head;
    }
    
    int rightCarry = carryRecurse(head -> next);
    if(rightCarry == 1){
        if(head -> data == 9){
            Node *temp = new Node(1);
            head -> data = 0;
            temp -> next = head;
            head = temp;
            return head;
        }
        else{
            head -> data = head -> data + 1;
            return head;
        }
    } else{
        return head;
    }
    
    
    
}