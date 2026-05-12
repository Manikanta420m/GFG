class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int r, int c, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {
        if(dp[r][c]) return dp[r][c];
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1;
        for(auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               matrix[nr][nc] > matrix[r][c]) {

                ans = max(ans,
                          1 + dfs(nr, nc, matrix, dp));
            }
        }
        return dp[r][c] = ans;
    }

    int longIncPath(vector<vector<int>>& matrix,
                              int n, int m) {

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans = max(ans, dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};