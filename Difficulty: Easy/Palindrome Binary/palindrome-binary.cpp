class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string s="";
        while(n>0){
            s+=(n&1?"1":"0");
            n/=2;
        }
        string rev=s;
        reverse(s.begin(),s.end());
        return s==rev;
    }
};