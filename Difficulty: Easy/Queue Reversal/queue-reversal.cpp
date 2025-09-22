class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        while(q.empty())return;
        int curr=q.front();
        q.pop();
        reverseQueue(q);
        q.push(curr);
    }
};