class Solution {
  public:
    const int M=1e9+7;
    int solve(string& s, int n,int i,int rem,vector<vector<int>>&dp){
        if(i==s.size())return 0;
        if(dp[i][rem]!=-1)return dp[i][rem];
        long long a=(rem*10+(s[i]-'0'))%n,b=0,c=0,d=0;
        if(a==0){
            b=1+solve(s,n,i+1,a,dp);
        }
        else{
            c=solve(s,n,i+1,a,dp);
        }
        d=solve(s,n,i+1,rem,dp);
        return dp[i][rem]=(b+c+d)%M;
    }
    int countSubsequences(string& s, int n) {
        // code here
        vector<vector<int>>dp(s.size(),vector<int>(n,-1));
        return solve(s,n,0,0,dp);
    }
};