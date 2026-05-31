// User function Template for C++

class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // code here
        return abs(b-a)%c==0;
    }
};