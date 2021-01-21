// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here
    node * prev = NULL;
    while(head != NULL){
        node * temp = head -> next;
        head -> next = prev;
        prev = head;
        head = temp;
    }
    
    return prev;
}

