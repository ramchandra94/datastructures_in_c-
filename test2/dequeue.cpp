/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class Deque {
    // Complete this class
    Node * head;
    Node * tail;
    int capacity;
    int size;
    public:
    Deque(int capacity){
        this -> capacity = capacity;
        this -> size = 0;
        this -> head = NULL;
        this -> tail = NULL;
    }
    
    void insertFront(int element){
        if(size == capacity){
            cout << -1 << endl;
            return;
        }
        Node * newNode = new Node(element);
        size++;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
        return;
        
    }
    
    void insertRear(int element){
        if(size == capacity){
            cout << -1 << endl;
            return;
        }
        Node *newNode = new Node(element);
        size++;
        if(tail == NULL){
            head = newNode;
            tail = newNode;
        }
        
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
        return;
    }
    
    void deleteFront(){
        if(size == 0){
            cout << -1 << endl;
            return;
        }
        
        Node *temp = head -> next;
        delete head;
        temp -> prev = NULL;
        head = temp;
        size--;
        return;
    }
    
    void deleteRear(){
        if(size == 0){
            cout << -1 << endl;
            return;
        }
        
        Node *temp = tail -> prev;
        delete tail;
        temp -> next = NULL;
        tail = temp;
        size--;
        return;
    }
    
    int getFront(){
        if(size == 0){
            return -1;
        }
        return head -> data;
    }
    
    int getRear(){
        if(size == 0){
            return -1;
        }
        return tail -> data;
    }
};
