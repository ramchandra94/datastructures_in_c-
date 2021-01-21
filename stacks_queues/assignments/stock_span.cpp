class Node {
	public:
    int data;
    int index;
    Node *next;
    Node(int data, int index){
        this -> data = data;
        this -> index = index;
    	this -> next = NULL;
    }
};

class Stack {
    Node *stackArr;

    int size;
    public:
    Stack(){
        stackArr = NULL;
        size = 0;
    }
    
    void push(int data, int index){
        Node *newNode = new Node(data, index);
        newNode -> next = stackArr;
        stackArr = newNode;
        size++;
    }
    
    void pop(){
        Node *temp = stackArr -> next;
        delete stackArr;
        stackArr = temp;
    }
    
    Node * top(){
        return stackArr;
    }
};

int* stockSpan(int *price, int size)  {
	// Write your code here
    Stack s;
    int * spanArr = new int[size];
    for(int i=0; i < size; i++){
        while(s.top() != NULL && s.top() -> data < price[i]){
            s.pop();
        }
        if(s.top() == NULL){
            spanArr[i] = i+1;
        }else{
            spanArr[i] = i - s.top() -> index;
        }
        s.push(price[i], i);
    }
    return spanArr;
}