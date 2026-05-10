class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
int sm1 = accumulate(a.begin(), a.end(), 0);
        int sm2 = accumulate(b.begin(), b.end(), 0);
        int diff = sm1 - sm2;
        if (diff % 2 != 0) return false;
        diff /= 2;

        unordered_set<int> st(a.begin(), a.end());

        for (int y : b) {
            if (st.find(y + diff) != st.end()) return true;
        }

        return false;
    }
};