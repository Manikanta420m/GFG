/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        int n=0;
        Node *temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }k--;
        int f=k,l=n-k-1,c=0;
        Node *fir=NULL,*las=NULL;
        temp=head;
        while(temp!=NULL){
            if(c==f)fir=temp;
            if(c==l)las=temp;
            temp=temp->next;
            c++;
        }
        if(fir && las){
        int dat=fir->data;
        fir->data=las->data;
        las->data=dat;}
        return head;
    }
};