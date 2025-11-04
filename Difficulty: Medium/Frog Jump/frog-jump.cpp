class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,1e9);
        dp[0]=0;
        for(int i=0;i<n-1;i++){
            dp[i+1]=min(dp[i]+abs(height[i]-height[i+1]),dp[i+1]);
            if(i+2<n)dp[i+2]=dp[i]+abs(height[i]-height[i+2]);
        }
        return dp[n-1];
    }
};