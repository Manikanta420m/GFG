class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=(mat[i][j]==1?1:0);
            }
            temp[i]=c;
        }
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=(mat[j][i]==1?1:0);
            }
            if(c==n and temp[i]==1){
                return i;
            }
        }
        return -1;
    }
};