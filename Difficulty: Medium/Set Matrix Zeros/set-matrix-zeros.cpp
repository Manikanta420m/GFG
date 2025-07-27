class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        unordered_set<int>r1,c1;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    c1.insert(j);
                    r1.insert(i);
                }
            }
        }
        vector<int>r,c;
        for(auto i:r1)r.push_back(i);
        for(auto i:c1)c.push_back(i);
        sort(c.begin(),c.end());
        sort(r.begin(),r.end());
        int k=0,x=r.size(),y=c.size();
        if(x==0 and y==0) return;
        for(int i=0;i<n;i++){
            int l=0;
            for(int j=0;j<m;j++){
                if( k<x and r[k]==i)mat[i][j]=0;
                if(l<y and c[l]==j )mat[i][j]=0,l++;
            }
            if(r[k]==i and k<x)k++;
        }
    }
};