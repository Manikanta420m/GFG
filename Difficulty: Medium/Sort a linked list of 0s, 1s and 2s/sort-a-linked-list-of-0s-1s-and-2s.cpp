/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int z=0,o=0,t=0;
        Node *temp=head;
        while(temp!=NULL){
            z+=(temp->data==0);
            o+=(temp->data==1);
            t+=(temp->data==2);
            temp=temp->next;
        }
        temp=head;
        while(z--){
            temp->data=0;
            temp=temp->next;
        }
        while(o--){
            temp->data=1;
            temp=temp->next;
        }
        while(t--){
            temp->data=2;
            temp=temp->next;
        }
        return head;
    }
};