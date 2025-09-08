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
  private:
    Node *findMiddle(Node *head){
        Node *slow=head;
        Node *fast=head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node *merge2(Node *list1,Node *list2){
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        while(list1!=NULL and list2!=NULL){
            if(list1->data < list2->data){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1)temp->next=list1;
        else temp->next=list2;
        return dummy->next;
    }
  public:
    Node* mergeSort(Node* head) {
        // code here
        if(head==NULL or head->next==NULL)return head;
        
        Node *mid=findMiddle(head);
        Node *right=mid->next;
        mid->next=NULL;
        Node *left=head;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        return merge2(left,right);
    }
};