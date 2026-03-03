class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int ans=0,l=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0)mp.erase(arr[l]);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};