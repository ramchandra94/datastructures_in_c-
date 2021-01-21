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

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    
    if(root == NULL){
        return 0;
    }
    
    int numLeafs = 0;
    for(int i=0; i < root->children.size(); i++){
        numLeafs += getLeafNodeCount(root->children[i]);
    }
    if(numLeafs == 0){
        return 1;
    }
    
    return numLeafs;
}