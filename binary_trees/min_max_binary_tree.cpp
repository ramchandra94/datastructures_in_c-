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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    pair<int, int> minMax = make_pair(INT_MAX, INT_MIN);
    
    if(root == NULL){
        return minMax;
    }
    
    pair<int, int> leftMinMax = getMinAndMax(root -> left);
    pair<int, int> rightMinMax = getMinAndMax(root -> right);
    
    minMax.first = min(root -> data, min(leftMinMax.first, rightMinMax.first));
    minMax.second = max(root->data, max(leftMinMax.second, rightMinMax.second));
    
    return minMax;

}