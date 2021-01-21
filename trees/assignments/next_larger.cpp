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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* nextNode = NULL;
    
    if(root -> data > x){
        nextNode = root;
    }
    
    for(int i=0; i < root->children.size(); i++){
        TreeNode<int>* nextChildNode = getNextLargerElement(root->children[i], x);
        if(nextNode != NULL){
            if(nextChildNode!= NULL && nextChildNode->data > x && nextChildNode->data < nextNode -> data){
                nextNode = nextChildNode;
            }
        }else{
            if(nextChildNode!= NULL && nextChildNode->data > x){
                nextNode = nextChildNode;
            }
        }
        
    }
    
    return nextNode;
}