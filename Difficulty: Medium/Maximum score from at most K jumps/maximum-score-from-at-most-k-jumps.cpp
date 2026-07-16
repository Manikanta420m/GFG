class Solution {
  public:
    int getScore(vector<int>& arr, int k) {
        // code here
        int ans=0;
        int n=arr.size();
        vector<long long>dp(n);
        deque<int>dq;
        dp[0]=arr[0];
        dq.push_back(0);
        for(int i=1;i<n;i++){
            while(!dq.empty() and dq.front()<i-k){
                dq.pop_front();
            }
            dp[i]=dp[dq.front()]+arr[i];
            while(!dq.empty() and dp[dq.back()]<=dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return (int)dp[n-1];
    }
};
