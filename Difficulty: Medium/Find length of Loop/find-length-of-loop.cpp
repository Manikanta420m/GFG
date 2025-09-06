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
    int lengthOfLoop(Node *head) {
        // code here
        Node *temp=head;
        int i=1;
        unordered_map<Node*,int>mp;
        while(temp!=NULL){
            if(mp[temp])return i-mp[temp];
            mp[temp]=i;
            i++;
            temp=temp->next;
        }
        return 0;
    }
};