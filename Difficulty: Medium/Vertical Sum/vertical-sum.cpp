/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
         map<int,int>mp;
         solve(root,0,mp);
         vector<int>ans;
         for(auto i:mp){
             ans.push_back(i.second);
         }
        return ans;
    }
    void solve(Node *root,int idx,map<int,int>&mp){
        if(!root)return ;
        mp[idx]+=root->data;
        solve(root->left,idx-1,mp);
        solve(root->right,idx+1,mp);
    }
};