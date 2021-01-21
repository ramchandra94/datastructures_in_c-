template <typename T>
class Node {
    public:
    T data;
    Node * next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class queue {
    public:
    Node<T> * head;
    Node<T> * tail;
    int size;
    
    queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    void push(T data){
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        size++;
    }
    
    T front(){
        if(head == NULL){
            return -1;
        }
        return head -> data;
    }
    
    void pop() {
        if(head == NULL){
            return;
        }
        
        Node<T> * temp = head;
        head = head -> next;
        size--;
        delete temp;
    }
    
    bool empty(){
        return size == 0;
    }
    

};



void reverseQueue(queue<int> &input) {
	// Write your code here
    
    if(input.size == 0){
        return;
    }
    
    int front = input.front();
    input.pop();
    reverseQueue(input);
    input.push(front);
    return;
}