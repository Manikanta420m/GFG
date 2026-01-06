class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int ans=0,res=0;
        for(int i=0;i<n;i++){
            ans^=arr[i];
            if(i==k-1)res=max(ans,res);
            if(i>=k)ans^=arr[i-k];
            else continue;
            res=max(ans,res);
        }
        return res;
    }
};