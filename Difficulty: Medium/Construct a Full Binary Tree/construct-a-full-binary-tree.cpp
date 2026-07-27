/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
     unordered_map<int,int>pos;
     int preIdx=0;
  private:
    Node* build(vector<int> &pre, vector<int> &preMirror,int l,int r){
        if(l>r)return NULL;
        Node *root=new Node(pre[preIdx++]);
        if(l==r)return root;
        int idx=pos[pre[preIdx]];
        root->left=build(pre,preMirror,idx,r);
        root->right=build(pre,preMirror,l+1,idx-1);
        return root;
    }
  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
         int n= pre.size();
         for(int i=0;i<n;i++){
             pos[preMirror[i]]=i;
         }
         preIdx=0;
         return build(pre,preMirror,0,n-1);
    }
};