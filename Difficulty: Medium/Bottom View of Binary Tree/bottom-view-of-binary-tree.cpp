/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        while(!q.empty()){
            Node *temp=q.front().first;
            int pos=q.front().second;
            q.pop();
            mp[pos]=temp->data;
            if(temp->left){
                q.push({temp->left,pos-1});
            }
            if(temp->right){
                q.push({temp->right,pos+1});
            }
        }
        for(auto i:mp)ans.push_back(i.second);
        return ans;
    }
};