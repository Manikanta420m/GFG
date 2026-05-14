class Solution {
  private:
    int solve(int i,int j,string S, string T,vector<vector<int>>&dp){
        if(i<0)return 1000;
        if(j<0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int k=j;
        for(;k>=0;k--){
            if(T[k]==S[i])break;
        }
        if(k<0)return 1;
        int op1=solve(i-1,j,S,T,dp);
        int op2=1+solve(i-1,k-1,S,T,dp);
        return dp[i][j]=min(op1,op2);
    }
  public:
    int shortestUnSub(string S, string T) {
        // code here
        int n=S.size(),m=T.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=solve(n-1,m-1,S,T,dp);
        return ans>=1000?-1:ans;
    }
};