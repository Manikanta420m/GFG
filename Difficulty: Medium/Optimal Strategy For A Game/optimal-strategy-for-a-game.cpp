class Solution {
  public:
  int dp[1001][1001];
    int solve(bool f,int l,int r,vector<int> &a){
        if(l>r)return 0;
        if (dp[l][r] != -1) return dp[l][r];
        if(f)return dp[l][r]=max(a[l]+solve(!f,l+1,r,a),a[r]+solve(!f,l,r-1,a));
        else return dp[l][r]=min(solve(!f,l+1,r,a),solve(!f,l,r-1,a));
    }
   
    int maximumAmount(vector<int> &arr) {
        memset(dp, -1, sizeof(dp));
        int l=0,r=arr.size()-1;
        return solve(1,l,r,arr);
    }
};