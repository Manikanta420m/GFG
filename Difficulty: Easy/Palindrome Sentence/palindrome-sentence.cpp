class Solution {
  public:
    bool isPalinSent(string &s1) {
        string s;
        for (char c : s1) {
            if (isalnum(c)) {
                s += tolower(c);
            }
        }

        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
