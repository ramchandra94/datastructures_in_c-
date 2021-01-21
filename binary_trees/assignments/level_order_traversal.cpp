/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> *pendingNodes = new queue<BinaryTreeNode<int>*>();
    pendingNodes->push(root);
    while(pendingNodes->size() != 0){
        int currSize = pendingNodes->size();
        for(int i=0; i < currSize; i++){
            BinaryTreeNode<int>* front = pendingNodes->front();
            pendingNodes->pop();
            cout << front->data << " ";
            if(front->left != NULL){
                pendingNodes->push(front->left);
            }
            if(front->right != NULL){
                pendingNodes->push(front->right);
            }
            
        }
        cout << endl;
    }
    
    delete pendingNodes;
}