class Solution {
  private:
    bool check(int mid,vector<int>&arr,int k,int m){
        int c=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid)c++;
            else c=0;
            if(c==k){ans++;c=0;}
        }
        return ans>=m;
    }
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        if(arr.size()<k*m)return -1;
        int l=*min_element(arr.begin(),arr.end());
        int r=*max_element(arr.begin(),arr.end());
        
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,arr,k,m))r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};