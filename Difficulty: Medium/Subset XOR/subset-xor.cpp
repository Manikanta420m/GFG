class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        int xr=0;
        vector<int>ans;
        for(int i=0;i<=n;i++)xr^=i;
        int skip=n^xr;
        for(int i=1;i<=n;i++)if(i!=skip)ans.push_back(i);
        return ans;
    }
};
