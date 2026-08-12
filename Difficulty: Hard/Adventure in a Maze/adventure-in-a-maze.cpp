class Solution {
  public:
    int dp[1001][1001];
    int cost[1001][1001];
    
    int MODE=1e9+7;
    virtual bool isValid(int i, int j, int n){
      return (i>=0 && j>=0 && i<n && j<n);    
    }
    
    virtual int totalPaths(int i, int j, int n, vector<vector<int>> &grid){
      if(i==n-1 && j==n-1) return 1;
      
      if(dp[i][j] != -1) return dp[i][j];
      
      int d=0, r=0;
      if(grid[i][j]==3){
        if(isValid(i+1, j, n)) d=totalPaths(i+1, j, n, grid);  
        if(isValid(i, j+1, n)) r=totalPaths(i, j+1, n, grid);  
      }
      else if(grid[i][j]==2){
        if(isValid(i+1, j, n)) d=totalPaths(i+1, j, n, grid);    
      }
      else{
         if(isValid(i, j+1, n)) r=totalPaths(i, j+1, n, grid);  
      }
      
      return dp[i][j]=(d+r)%MODE;
    }
    
    
    int svc(int i, int j, int n, vector<vector<int>>& grid) {
        if (i == n-1 && j == n-1)
            return grid[i][j];

         if(cost[i][j] != -1) return cost[i][j];
        
         
        int d = -1e9, r = -1e9;

        if ((grid[i][j] == 2 || grid[i][j] == 3) &&
            isValid(i+1, j, n))
            d = svc(i+1, j, n, grid);

        if ((grid[i][j] == 1 || grid[i][j] == 3) &&
            isValid(i, j+1, n))
            r = svc(i, j+1, n, grid);

        return cost[i][j]=grid[i][j] + max(d, r);
    }
    
    vector<int> findWays(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        memset(cost, -1, sizeof(cost));
        
        int n=grid.size();
        
        int c=0;
        
        vector<int> ans;
        ans.push_back(totalPaths(0, 0, n, grid));
        if(ans[0]==0) c=0;
        else c=svc(0, 0, n, grid);
        ans.push_back(c);
        return ans;
        
    }
};