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
  public:
    int dfs(int sum,Node *root, int k,unordered_map<int,int>&mp){
        if(!root)return 0;
        sum+=(root->data);
        int ans=0;
        if(mp.find(sum-k)!=mp.end())ans+=mp[sum-k];
        mp[sum]++;
        ans+=dfs(sum,root->left,k,mp);
        ans+=dfs(sum,root->right,k,mp);
        mp[sum]--;
        return ans;
    }
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int,int>mp;
        mp[0]=1;
        return dfs(0,root,k,mp);
    }
};