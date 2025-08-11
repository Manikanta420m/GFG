class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int mini=0,maxi=0,n=prices.size();
        k=(n+k)/(k+1);
        for(int i=0;i<k;i++){mini+=prices[i];maxi+=prices[n-i-1];}
        return {mini,maxi};
    }
};