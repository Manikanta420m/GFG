class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        k=k%(dq.size());
        if(type==1){
            while(k--){
                int ele=dq.back();
                dq.pop_back();
                dq.push_front(ele);
            }
        }
        else{
            while(k--){
                int ele=dq.front();
                dq.pop_front();
                dq.push_back(ele);
            }
        }
    }
};