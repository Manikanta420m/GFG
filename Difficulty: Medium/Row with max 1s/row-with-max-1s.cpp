// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n=arr.size();
        int m=arr[0].size();
        int ans=-1,maxi=m;
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(arr[i][mid]==1)r=mid-1;
                else l=mid+1;
            }
            if(l<m){
                if(l<maxi){
                    maxi=min(maxi,l);
                    ans=i;
                }
            }
        }
        return ans;
    }
};