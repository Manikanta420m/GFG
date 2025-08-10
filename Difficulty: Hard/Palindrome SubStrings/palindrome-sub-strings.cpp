class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n=s.size(),ans=0;
        if(n<2)return 0;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<n;i++)dp[i][i]=true;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j] and (len==2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    ans++;
                }
            }
        }
        return ans;
    }
};