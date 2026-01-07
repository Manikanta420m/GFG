class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            if(i==k-1){
               ans.push_back(mp.size()); 
            }
            if(i>=k){
                mp[arr[i-k]]--;
                if(mp[arr[i-k]]==0)mp.erase(arr[i-k]);
                ans.push_back(mp.size());
            }
        }
        return ans;
    }
};