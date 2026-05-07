/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

bool validate(Node* root1,Node* root2){
    if(!root2)return true;
    if(!root1)return false;
    if(root1->data!=root2->data)return false;
    return validate(root1->left,root2->left) and validate(root1->right,root2->right);
}

class Solution {
  public:
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        if(!root1)return false;
        if(root1->data==root2->data){
            bool check=validate(root1,root2);
            if(check)return true;
        }
        return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
    }
};