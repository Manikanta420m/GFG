class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
         int n=arr.size();
         int ans=0;
         while(true){
             int maxi=*max_element(arr.begin(),arr.end());
             if(maxi==0)break;
             ans=max(ans,ans^maxi);
             for(auto &i:arr)i=min(i,i^maxi);
         }
         return ans;
    }
};