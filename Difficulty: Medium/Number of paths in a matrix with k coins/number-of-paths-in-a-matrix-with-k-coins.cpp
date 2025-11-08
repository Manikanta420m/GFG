class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
int n = mat.size();
    int m = mat[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

    if (mat[0][0] <= k)
        dp[0][0][mat[0][0]] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c <= k; c++) {
                if (c < mat[i][j]) continue;
                if (i > 0)
                    dp[i][j][c] += dp[i - 1][j][c - mat[i][j]];
                if (j > 0)
                    dp[i][j][c] += dp[i][j - 1][c - mat[i][j]];
            }
        }
    }

    return dp[n - 1][m - 1][k];
    }
};