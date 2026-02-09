class Solution {
  public:
    int findKRotation(vector<int> &a) {
        // Code Here
        int ans=1;
        int n=a.size();
        if(n==1)return 0;
        for(int i=1;i<n;i++){
            if(a[i-1]>a[i])break;
            ans++;
            if(i==n-1)return 0;
        }
        return ans;
    }
};
