class Solution {
private:
    int solve(int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n == 2) return 1;

        if (dp[n] != -1) return dp[n];

        int tot = 0;
        for (int i = 1; i < n; i += 2) {
            int left = solve(i - 1, dp);
            int right = solve(n - i - 1, dp);
            tot += left * right;
        }

        return dp[n] = tot;
    }

public:
    int count(int N) {
        if (N & 1) return 0;   // odd number can't be paired

        vector<int> dp(N + 1, -1);
        return solve(N, dp);
    }
};