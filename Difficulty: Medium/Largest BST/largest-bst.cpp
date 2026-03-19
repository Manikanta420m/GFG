/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    tuple<int,int,int> solve(Node* root){
        if(!root)return {INT_MAX, INT_MIN, 0};
        auto [lmin, lmax, lc] = solve(root->left);
        auto [rmin, rmax, rc] = solve(root->right);
        if(root->data>lmax and root->data<rmin){
            return {min(lmin,root->data), max(root->data,rmax),lc+rc+1};
        }
        return {INT_MIN, INT_MAX, max(lc,rc)};
    }
    int largestBst(Node *root) {
        auto [l, r, c] = solve(root);
        return c;
    }
};