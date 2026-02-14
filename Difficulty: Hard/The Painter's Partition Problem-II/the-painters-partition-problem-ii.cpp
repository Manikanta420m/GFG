class Solution {
  public:
  int n;
    int check(int mid,vector<int>&a){
        int c=1;
        int sm=0;
        for(auto i:a){
            sm+=i;
            if(sm>mid){
                c++;
                sm=i;
            }
        }
        return c;
    }
    int minTime(vector<int>& a, int k) {
        // code here
        n=a.size();
        int l=*max_element(a.begin(),a.end());
        int r=accumulate(a.begin(),a.end(),0);
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,a)<=k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};