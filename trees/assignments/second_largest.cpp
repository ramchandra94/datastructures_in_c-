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

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    
    if(root == NULL){
        return NULL;
    }
    
    queue<TreeNode<int>*> treeNodes;
    
    treeNodes.push(root);
    
    TreeNode<int>* first = root;
    TreeNode<int>* second = NULL;
    
    while(treeNodes.size() != 0){
        TreeNode<int>* front = treeNodes.front();
        treeNodes.pop();
        for(int i=0; i < front->children.size(); i++){
            treeNodes.push(front->children[i]);
        }
        
        if(second == NULL){
            if(front -> data > first -> data){
                second = first;
                first = front;
            } else if(front -> data < first -> data){
                second = front;
            }
        } else{
            if(front -> data > first -> data){
                second = first;
                first = front;
            } else if(front -> data < first -> data){
                if(front -> data > second -> data){
                    second = first;
                }
            }
        }
    }
    return second;
}