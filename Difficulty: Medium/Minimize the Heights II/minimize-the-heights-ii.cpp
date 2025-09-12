class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n==1)return 0;
        sort(arr.begin(),arr.end());
        int ans=arr[n-1]-arr[0];
        int mini=arr[0]+k;
        int maxi=arr[n-1]-k;
        for(int i=0;i<n-1;i++){
            int minHt=min(mini,arr[i+1]-k);
            int maxHt=max(maxi,arr[i]+k);
            if(minHt<0)continue;
            ans=min(ans,maxHt-minHt);
        }
        return ans;
    }
};