class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n=cost.size();
        vector<int>dp(w+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(cost[i]==-1)continue;
            for(int j=i+1;j<=w;j++){
                if(dp[j-i-1]!=INT_MAX)dp[j]=min(dp[j],cost[i]+dp[j-i-1]);
            }
        }
        return dp[w]>=INT_MAX?-1:dp[w];
    }
};
