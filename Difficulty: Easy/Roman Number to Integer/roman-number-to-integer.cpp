class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int>r={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int ans=0;
        for(int i=0;i<s.size();i++){
            int cur=r[s[i]],nxt=0;
            if(i<s.size()-1)nxt=r[s[i+1]];
            if(nxt>cur)ans-=cur;
            else ans+=cur;
        }
        return ans;
    }
};