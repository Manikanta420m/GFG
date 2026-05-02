class Solution {
  public:
    int findPosition(int n) {
        // code here
        return ((n&(n-1))!=0?-1:32-__builtin_clz(n));
    }
};