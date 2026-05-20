class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        return (n!=0 and (n&(n+1))==0);
    }
};