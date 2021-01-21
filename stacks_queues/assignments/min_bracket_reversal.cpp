class Node {
    public:
    char data;
    Node * next;
    
    Node(char data){
        this -> data = data;
        this -> next = NULL;
    }
};


class Stack {
    public:
    Node *head;
    
    int size;

    Stack(){
        head = NULL;
        size = 0;
    }
    
    void push(char elem){
        Node * newNode = new Node(elem);
        newNode -> next = head;
        head = newNode;
        size++;
    }
    
    void pop(){
        if(head == NULL){
            return;
        }
        Node * temp = head -> next;
        delete head;
        head = temp;
        size--;
    }
    
    char top(){
        if(head == NULL){
            return '\0';
        }
        return head->data;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
};

int countBracketReversals(string input) {
	// Write your code here
    Stack s;
    int count = 0;
    for(int i=0; i < input.size(); i++){
        if(input[i] == '}'){
            if(s.isEmpty()){
                s.push('{');
                count++;
            }
            else{
                s.pop();
            }
        } 
        else {
            s.push('{');
        }
    }
    if(s.isEmpty()){
        return count;
    } else if(s.size % 2 == 0){
        return count + s.size/2;
    } else{
        return -1;
    }
}
