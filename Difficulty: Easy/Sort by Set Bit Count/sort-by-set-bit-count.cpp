class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        map<int,vector<int>>mp;
        for(auto i:arr){
            int bits=__builtin_popcount(i);
            mp[bits].push_back(i);
        }
        vector<int>ans;
        for(auto i:mp){
            vector<int>temp=i.second;
            while(temp.size()>0){ans.push_back(temp.back());temp.pop_back();}
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};