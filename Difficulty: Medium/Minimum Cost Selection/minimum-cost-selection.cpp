class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        vector<int>dp(3,0);
        dp[0]=mat[0][0];
        dp[1]=mat[0][1];
        dp[2]=mat[0][2];
        int ans=min(dp[0],min(dp[1],dp[2]));
        for(int i=1;i<mat.size();i++){
            int m0=dp[0],m1=dp[1],m2=dp[2];
            dp[0]=(mat[i][0]+min(m1,m2));
            dp[1]=(mat[i][1]+min(m0,m2));
            dp[2]=(mat[i][2]+min(m0,m1));
            ans=min(dp[0],min(dp[1],dp[2]));
        }
        return ans;
    }
};