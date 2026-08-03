class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int ans=0,cur=0,prev=0;
        int n=arr.size();
        for(int i=0;i<k;i++){
            cur+=arr[i];
        }ans=cur;
        for(int i=k;i<n;i++){
            cur+=(arr[i]-arr[i-k]);
            prev=max({0,arr[i-k],prev+arr[i-k]});
            ans=max(ans,cur+prev);
        }
        return ans;
    }
};