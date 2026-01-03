/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        vector<int>a;
        if(root==NULL or root->next==NULL)return root;
        Node *temp=root;
        while(temp){
            Node *t1=temp;
            while(t1!=NULL){
                a.push_back(t1->data);
                t1=t1->bottom;
            }
            temp=temp->next;
        }
        sort(a.begin(),a.end());
        Node *res=new Node(0);
        Node *it=res;
        for(int i=0;i<a.size();i++){
            Node *sx=new Node(a[i]);
            it->bottom=sx;
            it=it->bottom;
        }
        return res->bottom;
    }
};