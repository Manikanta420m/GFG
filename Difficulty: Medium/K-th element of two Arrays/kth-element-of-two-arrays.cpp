class Solution {
  public:
    int check(int mid,vector<int> &a, vector<int> &b){
        int cnt=0;
        cnt+=upper_bound(a.begin(),a.end(),mid)-a.begin();
        cnt+=upper_bound(b.begin(),b.end(),mid)-b.begin();
        return cnt;
    }
  
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n=a.size();
        int m=b.size();
        int l=min(a[0],b[0]),r=max(a[n-1],b[m-1]);
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,a,b)>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};