class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        for(int i=0;i<mat.size();i++){
            for(int j=i;j<mat[0].size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        return mat;
    }
};