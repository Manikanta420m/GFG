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
  private:
    bool compare(Node *h1,Node *h2){
        while(h1!=NULL and h2!=NULL){
            if(h1->data!=h2->data)return false;
            h1=h1->next;
            h2=h2->next;
        }
        return true;
    }
  
    Node* rev(Node *head){
        if(head==NULL)return head;
        Node *temp=head,*prev=NULL;
        while(temp){
            Node *nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        return prev;
    }
    
    Node *findMid(Node *head){
        Node *slow=head,*fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast)fast=fast->next;
        }
        return slow;
    }
  public:
    bool isPalindrome(Node *head) {
        //  code here
        if(head==NULL or head->next==NULL)return true;
        Node *h=head;
        Node *mid=findMid(h);
        Node *h2=rev(mid);
        return compare(h,h2);
    }
};