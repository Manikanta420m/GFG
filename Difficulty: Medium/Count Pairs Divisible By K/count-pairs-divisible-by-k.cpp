class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        int ans=0;
      //  for(auto &i:arr)i=i%k;
     //   for(auto &i:arr)cout<<i<<" ";
       vector<int>f(k+1,0);
      //  unordered_map<int,int>mp;
      //  for(auto i:arr)mp[i]++;
        for(auto &i:arr){
            i%=k;
            int req=(k-i)%k;
            ans+=f[req];
            f[i]++;
        }
        return ans;
    }
};