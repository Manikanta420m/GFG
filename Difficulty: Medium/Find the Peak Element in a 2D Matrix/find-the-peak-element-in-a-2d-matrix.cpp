class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int l=INT_MIN,r=INT_MIN,t=INT_MIN,d=INT_MIN;
                if(j>0)l=mat[i][j-1];
                if(i>0)t=mat[i-1][j];
                if(j<m-1)r=mat[i][j+1];
                if(i<n-1)d=mat[i+1][j];
                int ele=mat[i][j];
                if(ele>=l and ele>=r and ele>=t and ele>=d)return {i,j};
            }
        }
        return {-1,-1};
    }
};
