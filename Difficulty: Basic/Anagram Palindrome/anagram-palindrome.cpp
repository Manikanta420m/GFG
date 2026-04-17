class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int>f(26,0);
        for(auto i:s){
            f[i-'a']++;
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(f[i]&1)c++;
        }
        if(s.size()&1 and c==1)return true;
        else if(s.size()&1)return false;
        return c==0;
    }
};