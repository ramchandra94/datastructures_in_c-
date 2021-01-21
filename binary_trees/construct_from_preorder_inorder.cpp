/***********************************************************
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

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    
    int root = *preorder;
    BinaryTreeNode<int>* treeRoot = new BinaryTreeNode<int>(root);
    
    if(preLength == 1){
        return treeRoot;
    }
    
    int* leftPreOrder = preorder + 1;
    int* leftInOrder = inorder;
    int leftInLength = 0;
    int* temp = inorder;

    while(*temp != root){
        leftInLength++;
        temp++;
    }
	
    if(leftInLength > 0){
    	treeRoot -> left = buildTree(leftPreOrder, leftInLength, leftInOrder, leftInLength);    
    }
    
    
    int rightInLength = preLength - 1 - leftInLength;
    
    if(rightInLength > 0){
        int *rightInOrder = temp + 1;
        int *rightPreOrder = leftPreOrder + leftInLength;
        treeRoot -> right = buildTree(rightPreOrder, rightInLength, rightInOrder, rightInLength);
    }
    return treeRoot;
}