class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int ans=INT_MIN;
        int n=mat.size(),m=mat[0].size();
        for(int k=0;k<m;k++){
            vector<int>a(n,0);
            for(int i=k;i<m;i++){
                for(int j=0;j<n;j++){
                    a[j]+=mat[j][i];
                }
                int sm=0;
                for(int j=0;j<n;j++){
                    sm+=a[j];
                    ans=max(ans,sm);
                    if(sm<0)sm=0;
                }
            }
        }
        return ans;
    }
};
