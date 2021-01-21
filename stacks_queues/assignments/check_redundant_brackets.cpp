class Node {
    	public :
    	char data;
    	Node *next;

    	Node(char data) {
        	this->data = data;
        	next = NULL;
    	}
};

class Stack {
	// Define the data members
    Node * head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size == 0;
    }

    void push(char element) {
        // Implement the push() function
        Node * newNode = new Node(element);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    char pop() {
        // Implement the pop() function
        if(head == NULL){
            return -1;
        }
        Node * temp = head;
        head = head -> next;
        int lastElem = temp -> data;
        delete temp;
        size--;
        return lastElem;
    }

    char top() {
        // Implement the top() function
        if(head == NULL){
            return -1;
        }
        return head -> data;
    }
};

bool checkRedundantBrackets(string expression) {
	// Write your code here
    
	Stack s;    
    int count;
    for(int i=0; i < expression.size(); i++){
        if(expression[i] == ')'){
            count = 0;
            while(s.top() != '('){
                s.pop();
                count++;
            }
            if(count <= 1){
                return true;
            }
            s.pop();
        } else{
            s.push(expression[i]);
        }
    }
    
    return false;
}