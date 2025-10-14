/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    int solve(Node *root,int &l,int &r){
        if(!root){
            return 0;
        }
        if(root->data>=l and root->data<=r){
            return root->data+solve(root->left,l,r)+solve(root->right,l,r);
        }
        if(root->data<l)return solve(root->right,l,r);
        return solve(root->left,l,r);
    }
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        return solve(root,l,r);
    }
};
