class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int close=count(s.begin(),s.end(),')');
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')open++;
            else close--;
            if(open==close)return i+1;
        }
        return false;
    }
};