class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        map<int,int>mp;
        int ans=0,cur=0;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            cur+=arr[i];
            ans+=mp[cur-k];
            mp[cur]++;
        }return ans;
    }
};