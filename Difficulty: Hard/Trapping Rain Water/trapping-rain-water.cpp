class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0,r=n-1;
        int lx=0,rx=0,ans=0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(lx>arr[l]){
                    ans+=lx-arr[l];
                }
                else{
                    lx=arr[l];
                }
                l++;
            }
            else{
                if(rx>arr[r]){
                    ans+=rx-arr[r];
                }
                else{
                    rx=arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};