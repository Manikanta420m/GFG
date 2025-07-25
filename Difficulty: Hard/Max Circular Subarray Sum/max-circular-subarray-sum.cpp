class Solution {
  private:
    int solve(vector<int>&a){
        int ans=0,sm=0,maxi=0,n=a.size();
        for(int i=0;i<n;i++){
            sm+=a[i];
            if(sm<0)sm=0;
            maxi=max(maxi,sm);
        }
        return maxi;
    }
  public:
    int maxCircularSum(vector<int> &arr) {
        int mx=*max_element(arr.begin(),arr.end());
        if(mx<0)return mx;
        int r1=solve(arr);
        int sm=accumulate(arr.begin(),arr.end(),0);
        for(auto &i:arr)i*=-1;
        int r2=solve(arr);
        return max(r1,sm+r2);
    }
};