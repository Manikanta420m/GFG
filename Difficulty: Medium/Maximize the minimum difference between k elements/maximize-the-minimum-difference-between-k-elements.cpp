class Solution {
  private:
    bool check(int mid,vector<int>&arr,int k){
        int ans=1,pre=arr[0];
        for(int i=1;i<arr.size();i++){
            if(abs(pre-arr[i])>=mid){pre=arr[i];ans++;}
        }
        return ans>=k;
    }
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int l=0,r=*max_element(arr.begin(),arr.end())-*min_element(arr.begin(),arr.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,arr,k))l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};
