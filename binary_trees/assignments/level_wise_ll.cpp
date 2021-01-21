/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> a;
    if(root == NULL){
        return a;
    }
    queue<BinaryTreeNode<int>*> pendingNodes; 
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        int size = pendingNodes.size();
        Node<int>* head;
        Node<int>* tail;
        for(int i=0; i < size; i++){
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            Node<int>* node = new Node<int>(front->data);
            if(i==0){
                head = node;
                tail = node;
            } else {
                tail -> next = node;
                tail = tail -> next;
            }
            if(front -> left != NULL){
                pendingNodes.push(front->left);
            }
            if(front -> right != NULL){
                pendingNodes.push(front->right);
            }
        }
        a.push_back(head);
    }
    return a;
}