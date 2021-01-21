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

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    int root = *(postorder + postLength - 1);
    
    BinaryTreeNode<int>* treeRoot = new BinaryTreeNode<int>(root);
    if(postLength == 1){
        return treeRoot;
    }
    int *temp = inorder;
    
    int leftInLength = 0;
    while(*temp != root){
        leftInLength++;
        temp++;
    }
    
    if(leftInLength > 0){
        treeRoot -> left = buildTree(postorder, leftInLength, inorder, leftInLength);
    }
    
    int rightInLength = postLength - 1 - leftInLength;
    if(rightInLength > 0){
        int *rightInOrder = ++temp;
        int *rightPostOrder = postorder + leftInLength;
        treeRoot -> right = buildTree(rightPostOrder, rightInLength, rightInOrder, rightInLength);
    }
    
    return treeRoot;
}