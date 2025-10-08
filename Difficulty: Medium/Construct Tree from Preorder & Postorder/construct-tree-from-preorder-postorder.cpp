/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    Node *solve(int &i,int &j,vector<int> &pre, vector<int> &post){
        Node *node=new Node(pre[i]);
        i++;
        if(node->data==post[j]){
            j++;
            return node;
        }
        Node *left=solve(i,j,pre,post);
        node->left=left;
        Node *right=solve(i,j,pre,post);
        node->right=right;
        j++;
        return node;
    }
  public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int i=0,j=0;
        return solve(i,j,pre,post);
    }
};