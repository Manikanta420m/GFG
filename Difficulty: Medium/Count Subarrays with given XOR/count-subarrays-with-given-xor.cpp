class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long ans=0;
        unordered_map<int,int>mp;
        int xr=0;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            xr^=arr[i];
            if(mp.find(xr^k)!=mp.end())ans+=mp[xr^k];
            mp[xr]++;
        }
        return ans;
    }
};