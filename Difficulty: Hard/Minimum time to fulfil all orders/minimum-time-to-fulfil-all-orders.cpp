class Solution {
  private:
    bool check(int mid,vector<int>& ranks, int n){
        int cnt=0;
        for(auto i:ranks){
            cnt+=(-1+sqrt(1+(8*mid)/i))/2;
            if(cnt>=n)return true;
        }
        return false;
    }
  public:
    int minTime(vector<int>& ranks, int n) {
         int mini=*min_element(ranks.begin(),ranks.end());
         int l=0,r=mini*(n*(n+1)/2);
         int ans=0;
         while(l<=r){
             int mid=l+(r-l)/2;
             if(check(mid,ranks,n)){
                 ans=mid;
                 r=mid-1;
             }
             else l=mid+1;
         }
         return ans;
    }
};