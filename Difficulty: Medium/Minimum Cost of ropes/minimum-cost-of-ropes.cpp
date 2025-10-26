class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        int ans=0;
        while(pq.size()>1){
            int ele1=pq.top();
            pq.pop();
            int ele2=pq.top();
            pq.pop();
            ans+=(ele1+ele2);
            pq.push(ele1+ele2);
        }
        return ans;
    }
};