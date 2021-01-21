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
#include<stack>

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int level = 1;
    while(pendingNodes.size() != 0){
        int size = pendingNodes.size();
        stack<int> temp;
        for(int i=0; i < size; i++){
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            if(level % 2 != 0){
               cout << front -> data << " "; 
            }
            else{
               temp.push(front -> data); 
            }
            
            if(front -> left != NULL){
                pendingNodes.push(front -> left);
            }
            if(front -> right != NULL){
                pendingNodes.push(front -> right);
            }
        }
        int tempSize = temp.size();
        for(int i=0; i< tempSize; i++){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
        level++;
    }
} 