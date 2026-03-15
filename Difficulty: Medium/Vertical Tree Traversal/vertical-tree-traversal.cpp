/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            mp[it.second].push_back(it.first->data);
            Node *node=it.first;
            int idx=it.second;
            if(node->left)q.push({node->left,idx-1});
            if(node->right)q.push({node->right,idx+1});
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            vector<int>res;
            for(auto j:i.second)res.push_back(j);
            ans.push_back(res);
        }
        return ans;
    }
};