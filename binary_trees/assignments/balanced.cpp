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
pair<bool, int> helper(BinaryTreeNode<int> *root){
    if(root == NULL){
        return make_pair(true, 0);
    }
    
    pair<bool, int> left = helper(root -> left);
    pair<bool, int> right = helper(root -> right);
    
    if(left.first && right.first && abs(left.second - right.second) <= 1){
        return make_pair(true, 1 + max(left.second, right.second));
    }
    else{
        return make_pair(false, 1 + max(left.second, right.second));
    }
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    return helper(root).first;
}