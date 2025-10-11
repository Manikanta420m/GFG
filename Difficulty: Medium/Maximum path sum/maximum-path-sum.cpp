/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    int solve(Node *root,int &ans){
        if(root==NULL)return 0;
        
        int sum=root->data;
        
        int leftsum=solve(root->left,ans);
        int rightsum=solve(root->right,ans);
        
        ans=max(ans,sum+max(0,leftsum)+max(0,rightsum));
        return sum+max(0,max(leftsum,rightsum));
    }
  public:
    int findMaxSum(Node *root) {
        // code here
        int ans=root->data;
        solve(root,ans);
        return ans;
    }
};