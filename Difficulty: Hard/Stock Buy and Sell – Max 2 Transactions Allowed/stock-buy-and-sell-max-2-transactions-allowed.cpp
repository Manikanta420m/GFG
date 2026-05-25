class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        if(n<2)return 0;
        vector<int>left(n,0),right(n,0);
        int mini=prices[0];
        for(int i=1;i<n;i++){
            mini=min(mini,prices[i]);
            left[i]=max(left[i-1],prices[i]-mini);
        }
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,prices[i]);
            right[i]=max(right[i+1],maxi-prices[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};