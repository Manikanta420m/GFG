/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void inorder(Node *root,int &k,int &ans){
        if(!root or ans!=-1)return;
        
        inorder(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->data;
            return;
        }
        
        inorder(root->right,k,ans);
    }
  public:
    int kthSmallest(Node *root, int k) {
        // code here
        int ans=-1;
        inorder(root,k,ans);
        return ans;
    }
};