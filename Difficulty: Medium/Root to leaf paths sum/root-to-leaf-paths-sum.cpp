/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
     void findsum(Node *root,int &sum, int num){
        
        if(!root)
        return;
        
        num = num+root->data;
        
        if(!root->left && !root->right){
            sum=sum+num;
            return;
        }
        
        findsum(root->left,sum,num*10);
        findsum(root->right,sum,num*10);
         
    }
    
    
    int treePathsSum(Node *root) {
        // code here.
        int sum=0;
        int num=0;
        findsum(root,sum,num);
        return sum;
    }
};