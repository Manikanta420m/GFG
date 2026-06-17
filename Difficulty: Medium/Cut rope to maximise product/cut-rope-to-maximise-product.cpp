class Solution {
  private:
    int solve(int n,vector<int>&dp){
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int c=1;
        for(int i=1;i<=n;i++){
            int x=i*solve(n-i,dp);
            c=max(c,x);
        }
        return dp[n]=c;
    }
  public:
    int maxProduct(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};