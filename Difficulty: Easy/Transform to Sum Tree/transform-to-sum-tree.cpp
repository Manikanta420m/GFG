/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
private:
    int solve(Node* node){
        if(node == NULL){
            return 0;
        }
        int a = solve(node->left);
        int b = solve(node->right);
        int c = node->data;
        node->data = a + b;
        return a+b+c;
    }
public:
    void toSumTree(Node *node) {
       int d = solve(node);
    }
};