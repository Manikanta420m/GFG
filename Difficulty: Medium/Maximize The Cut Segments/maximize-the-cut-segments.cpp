class Solution {
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        int dp[n+1];
        dp[0]=0;
        
        for(int i=1;i<n+1;i++)
        dp[i]=INT_MIN;
        
        for(int i=1;i<n+1;i++)
        {
            if(x<=i)
            dp[i]=max(dp[i], 1+ dp[i-x]);
            if(y<=i)
            dp[i]=max(dp[i],1+dp[i-y]);
            if(z<=i)
            dp[i]=max(dp[i],1+dp[i-z]);
            
            //dp[i]=max(dp[i],dp[i-1]);
        }
        
        if(dp[n]<0)
        return 0;
        
        return dp[n];

    }
};