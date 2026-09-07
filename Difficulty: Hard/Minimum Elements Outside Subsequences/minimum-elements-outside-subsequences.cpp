class Solution {
  public:
    int minCount(vector<int>& arr) {
        // code here
        int n = arr.size();

                // dp[i][j]:
                // maximum number of elements used when
                // i = last index of increasing subsequence
                // j = last index of decreasing subsequence
                //
                // n represents "no element chosen yet"
                vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

                dp[n][n] = 0;

                for (int k = 0; k < n; k++) {
                    vector<vector<int>> ndp = dp;

                    for (int i = 0; i <= n; i++) {
                        for (int j = 0; j <= n; j++) {
                            if (dp[i][j] == -1)
                                continue;

                            // Leave arr[k] unused
                            ndp[i][j] = max(ndp[i][j], dp[i][j]);

                            // Put arr[k] into increasing subsequence
                            if (i == n || arr[k] > arr[i]) {
                                ndp[k][j] = max(ndp[k][j], dp[i][j] + 1);
                            }

                            // Put arr[k] into decreasing subsequence
                            if (j == n || arr[k] < arr[j]) {
                                ndp[i][k] = max(ndp[i][k], dp[i][j] + 1);
                            }
                        }
                    }

                    dp.swap(ndp);
                }

                int maximumUsed = 0;

                for (int i = 0; i <= n; i++) {
                    for (int j = 0; j <= n; j++) {
                        maximumUsed = max(maximumUsed, dp[i][j]);
                    }
                }

                return n - maximumUsed;

    }
};