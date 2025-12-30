/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

Node* rev(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* newHead = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

class Solution {
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        Node* r1=rev(head1);
        Node* r2=rev(head2);
        Node *t1=r1,*t2=r2;
        Node *temp=new Node(0);
        Node *res=temp;
        int carry=0;
        while(t1 or t2 or carry){
            int res=carry;
            if(t1){
                res+=t1->data;
                t1=t1->next;
            }
            if(t2){
                res+=t2->data;
                t2=t2->next;
            }
            Node *mani=new Node(res%10);
            temp->next=mani;
            temp=temp->next;
            carry=res/10;
        }
        Node* ans=rev(res->next);
        while(ans->data==0)ans=ans->next;
        return ans;
    }
};































