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


bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1 == NULL && root2 == NULL){
        return true;
    } else if(root1 != NULL && root2 != NULL){
        bool flag;
        if(root1 -> data == root2 -> data){
            flag = true;
        }else{
            return false;
        }
        for(int i=0; i < root1->children.size(); i++){
            bool childFlag = areIdentical(root1->children[i], root2->children[i]);
            if(!childFlag){
                return false;
            }
        }
        return flag;
    } else{
        return false;
    }
}