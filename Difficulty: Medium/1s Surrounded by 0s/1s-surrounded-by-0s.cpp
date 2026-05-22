class Solution {
  public:
     void dfs(int i, int j,vector<vector<int>> &grid ){
                 int n=grid.size(), m=grid[0].size();

         if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return;
         grid[i][j]=0;
         int dx[]={-1, 1,0,0};
         int dy[]= {0, 0, -1,1};
         
         for(int d=0 ; d<4; d++){
             int x=i+dx[d], y=j+dy[d];
             dfs(x,y, grid);
         }
         
     }
    int cntOnes(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        int c=0;
        
        for(int i=0; i<n; i++){
            if(grid[i][0]==1) dfs(i, 0, grid);
            if(grid[i][m-1]==1) dfs(i, m-1, grid);
        }
        
        for(int j=0; j<m; j++){
            if(grid[0][j]==1) dfs(0, j, grid);
            if(grid[n-1][j]==1) dfs(n-1, j, grid);
        }
        

        for(int i=1; i<n-1 ; i++){
            for(int j=1 ; j<m-1; j++){
                if(grid[i][j]==1) c++;
            }
        }
        return c;
    }
};
