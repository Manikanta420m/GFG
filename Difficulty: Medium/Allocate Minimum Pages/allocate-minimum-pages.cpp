class Solution {
  private :
      bool check(int mid,vector<int>&arr,int k){
          int c=1,sm=0;
          for(int i=0;i<arr.size();i++){
              if(sm+arr[i]>mid){
                  c++;
                  sm=arr[i];
                  if(c>k)return false;
              }
              else sm+=arr[i];
          }
          return true;
      }
  public:
    int findPages(vector<int> &arr, int k) {
        if(arr.size()<k)return -1;
        long long l=*max_element(arr.begin(),arr.end());
        long long r=accumulate(arr.begin(),arr.end(),0LL);
        
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,arr,k))r=mid-1;
            else l=mid+1;
        }
        return (int)l;
    }
};