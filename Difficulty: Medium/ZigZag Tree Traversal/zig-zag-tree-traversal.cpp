/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        vector<int>ans;
        queue<Node *>q;
        q.push(root);
        int f=1;
        while(!q.empty()){
            int n=q.size();
            vector<int>lvl;
            for(int i=0;i<n;i++){
                Node *cur=q.front();
                q.pop();
                lvl.push_back(cur->data);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            for(int i=0;i<n;i++){
               ans.push_back(lvl[f?i:n-i-1]); 
            }
            f=!f;
        }
        return ans;
    }
};