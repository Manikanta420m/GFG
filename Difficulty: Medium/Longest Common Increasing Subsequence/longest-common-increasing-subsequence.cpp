class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int m=b.size(),ans=0;
        vector<int>dp(m,0);
        for(auto i:a){
            int c=0;
            for(int j=0;j<m;j++){
                if(i==b[j])dp[j]=max(dp[j],c+1);
                if(b[j]<i)c=max(c,dp[j]);
            }
        }
        for(auto x:dp)ans=max(ans,x);
        return ans;
    }
};