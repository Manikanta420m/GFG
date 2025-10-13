class Solution {
  private:
    unordered_map<Node*,int>dp;
    
    int solve(Node *root){
        if(!root)return 0;
        if(dp[root])return dp[root];
        
        int skip1=solve(root->left);
        int skip2=solve(root->right);
        
        int a=0,b=0,c=0,d=0;
        if(root->left){
            a=solve(root->left->right);
            b=solve(root->left->left);
        }
        if(root->right){
            c=solve(root->right->left);
            d=solve(root->right->right);
        }
        int include=root->data+a+b+c+d;
        int exclude=skip1+skip2;
        
        return dp[root]=max(include,exclude);
    }
  public:
    int getMaxSum(Node *root) {
       return solve(root);
    }
};