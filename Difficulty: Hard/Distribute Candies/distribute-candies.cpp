/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  private:
    int solve(Node* root,int &ans){
        if(!root)return 0;
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        ans+=abs(l)+abs(r);
        return root->data-1+l+r;
    }
  public:
    int distCandy(Node* root) {
        // code here
        int ans=0;
        solve(root,ans);
        return ans;
    }
};