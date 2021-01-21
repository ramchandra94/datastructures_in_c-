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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* maxNode = root;
    for(int i=0; i < root->children.size(); i++){
        TreeNode<int>* tempNode = maxDataNode(root->children[i]);
        if(tempNode->data > maxNode->data){
            maxNode = tempNode;
        }
    }
    return maxNode;
}