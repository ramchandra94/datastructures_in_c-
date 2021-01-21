/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

int nodeChildSum(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    
    int sum = root -> data;
    for(int i=0; i < root->children.size(); i++){
        sum += root->children[i]->data;
    }
    
    return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    
    if(root == NULL){
        return NULL;
    }
    
    int maxSum = nodeChildSum(root);
    TreeNode<int>* maxNode = root;
    
    for(int i=0; i < root->children.size(); i++){
        TreeNode<int>* maxChildNode = maxSumNode(root->children[i]);
        if(nodeChildSum(maxChildNode) > maxSum){
            maxNode = maxChildNode;
        }
    }
    
    return maxNode;
}