/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(!head or !head->next) return head;
        
        Node *cur=head;
        Node *prev=NULL;
        
        while(cur!=NULL){
            Node *nxt=cur->next;
            cur->next=prev;
            cur->prev=nxt;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
};