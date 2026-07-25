class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n=mat.size(),m=mat[0].size(),ans=INT_MIN;
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i+1][j+1]=pre[i][j+1]+pre[i+1][j]-pre[i][j]+mat[i][j];
                if(i>=k-1 and j>=k-1){
                    ans=max(ans,pre[i+1][j+1]-pre[i-k+1][j+1]-pre[i+1][j-k+1]+pre[i-k+1][j-k+1]);
                }
            }
        }
        return ans;
    }
};