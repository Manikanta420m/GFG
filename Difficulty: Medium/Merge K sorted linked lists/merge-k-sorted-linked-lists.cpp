/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        vector<int>v;
        for(auto i:arr){
            while(i!=NULL){
                v.push_back(i->data);
                i=i->next;
            }
        }
        sort(v.begin(),v.end());
        Node *head=new Node(v[0]);
        Node *temp=head;
        for(int i=1;i<v.size();i++){
            temp->next=new Node(v[i]);
            temp=temp->next;
        }
        return head;
    }
};