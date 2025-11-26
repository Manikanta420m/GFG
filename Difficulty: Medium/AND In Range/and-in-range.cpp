class Solution {
public:
    int andInRange(int l, int r) {
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = 1 << i;
            if ((l >> (i + 1)) == (r >> (i + 1))) {
                if (((l >> i) & 1) == 1) ans |= bit;
            }
        }
        return ans;
    }
};
