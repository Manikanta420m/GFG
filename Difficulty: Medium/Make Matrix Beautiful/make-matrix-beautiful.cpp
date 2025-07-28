class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        long long maxi=0;
        vector<long long>a(n,0);
        for(int i=0;i<n;i++){
            long long ans=0;
            for(int j=0;j<n;j++){
                ans+=mat[i][j];
                a[j]+=mat[i][j];
                maxi=max(maxi,a[j]);
            }
            maxi=max(maxi,ans);
        }
        int ans=0;
        for(auto i:a)ans+=(maxi-i);
        return ans;
    }
};