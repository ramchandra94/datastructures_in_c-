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
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        cout << front -> data << ":L:";
        if(front -> left != NULL){
            cout << front -> left -> data;
            pendingNodes.push(front -> left);
        } else{
            cout << "-1";
        }
        
        cout << ",R:";
        if(front -> right != NULL){
            cout << front->right -> data;
            pendingNodes.push(front -> right);
        } else{
            cout << "-1";
        }
        cout << endl;
        
    }
}