class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));
        for(auto it:opr){
            int val=it[0];
            int r1=it[1];
            int c1=it[2];
            int r2=it[3];
            int c2=it[4];
            temp[r1][c1]+=val;
            if(c2+1<m){
                temp[r1][c2+1]-=val;
                if(r2+1<n){
                    temp[r2+1][c2+1]+=val;
                }
            }
            if(r2+1<n){
                temp[r2+1][c1]-=val;
             }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                temp[i][j]=temp[i][j]+temp[i][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                temp[j][i]=temp[j][i]+temp[j-1][i];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=temp[i][j]+mat[i][j];
            }
        }
        return mat;
    }
};