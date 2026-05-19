class Solution {
  public:
  
    int dfs(vector<vector<int>>& grid, int row, int col,
            vector<vector<bool>>& vis) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // Mark visited
        vis[row][col] = true;
        int area = 1;
        
        // 8 directions
        int movex[] = {1,1,0,-1,-1,-1,0,1};
        int movey[] = {0,1,1,1,0,-1,-1,-1};
        
        for(int k = 0; k < 8; k++) {
            int newRow = row + movey[k];
            int newCol = col + movex[k];
            
            if(newRow >= 0 && newRow < n &&
               newCol >= 0 && newCol < m &&
               !vis[newRow][newCol] &&
               grid[newRow][newCol] == 1) {
                   
                area += dfs(grid, newRow, newCol, vis);
            }
        }
        return area;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    ans = max(ans, dfs(grid, i, j, vis));
                }
            }
        }
        return ans;
    }
};