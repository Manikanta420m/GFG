// User function Template for C++

class Solution {
  public:
    int sum(int a, int b) {
        // code here
        return b==0?a:sum(a^b,(a&b)<<1);
    }
};