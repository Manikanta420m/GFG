class Solution {
  public:
    int MODE=1e9+7;

    virtual int prefixStrings(int n){
      vector<long long int> dp(n+1, 0);
      dp[0]=1; dp[1]=1;

      for(int i=2; i<=n; i++){
         int l=0, r=i-1;

         while(l<i && r>=0){
           (dp[i]+=((dp[l]%MODE)*(dp[r]%MODE))%MODE)%MODE;
           l++; r--;
         }

      }

      return dp[n]%MODE;
    }
};