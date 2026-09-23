class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        int totalSum = accumulate(begin(arr), end(arr), 0);

        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        right[n-1] = 1;

        for (int i = 1; i < n; ++i) {

            left[i] = min(left[i-1] + 1, arr[i]);
        }

        for (int i = n-2; i >= 0; --i) {

            right[i] = min(right[i+1] +1 , arr[i]);
        }


        int maxPyramidPeek = 0;

        for (int i = 0; i < n; i++) {

            int peek = min(left[i], right[i]);
            maxPyramidPeek = max(maxPyramidPeek, peek);
        }

        int pyramidTotalSum =maxPyramidPeek * maxPyramidPeek;

        int cost = totalSum - pyramidTotalSum;


        return cost;
    }
};

