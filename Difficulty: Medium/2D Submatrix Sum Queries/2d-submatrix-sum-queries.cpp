class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int pref=0;
            for(int j=0;j<m;j++){
                int temp=mat[i][j];
                if(i>0)mat[i][j]+=(pref+mat[i-1][j]);
                else mat[i][j]+=pref;
                pref+=temp;
               // cout<<mat[i][j]<<" ";
            }
           // cout<<endl;
        }
        for(auto i:queries){
            int r1=i[0],c1=i[1],r2=i[2],c2=i[3];
            int res=mat[r2][c2]-(c1?mat[r2][c1-1]:0)-(r1?mat[r1-1][c2]:0)+(r1 and c1?mat[r1-1][c1-1]:0);
            ans.push_back(res);
        }
        return ans;
    }
};
