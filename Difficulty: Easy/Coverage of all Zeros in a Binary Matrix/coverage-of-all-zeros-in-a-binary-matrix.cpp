class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size(),ans=0;
        vector<int>rev(n,-1),bot(m,-1);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==1){
                    rev[i]=j;
                    break;
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                if(mat[i][j]==1){
                    bot[j]=i;
                    break;
                }
            }
        }
        vector<int>lf(n,-1),tp(m,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    lf[i]=j;
                    tp[j]=i;
                }
                else{
                    if(lf[i]<=j and lf[i]!=-1)ans++;
                    if(tp[j]<=i and tp[j]!=-1)ans++;
                    if(rev[i]>=j and rev[i]!=-1)ans++;
                    if(bot[j]>=i and bot[j]!=-1)ans++;
                }
            }
        }
        return ans;
    }
};