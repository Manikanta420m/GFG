class Solution {
public:
    int maxIndexDiff(vector<int>& arr) {
        int n = arr.size();

        vector<int> LMin(n), RMax(n);

        LMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            LMin[i] = min(LMin[i - 1], arr[i]);
        }

        RMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            RMax[i] = max(RMax[i + 1], arr[i]);
        }

        int i = 0, j = 0;
        int ans = -1;

        while (i < n && j < n) {
            if (LMin[i] <= RMax[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};