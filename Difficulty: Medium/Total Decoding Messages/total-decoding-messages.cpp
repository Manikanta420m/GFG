class Solution {
  private:
    int solve(int idx,string &digits,vector<int>&dp){
        if(idx==digits.size())return 1;
        if(dp[idx]!=-1)return dp[idx];
        if(digits[idx]=='0')return 0;
        int op1=0,op2=0;
        int num=digits[idx]-'0';
        if(idx<digits.size()-1)num=num*10+digits[idx+1]-'0';
        op1=solve(idx+1,digits,dp);
        if(idx<digits.size()-1 and (num>=10 and num<=26)){
            op2=solve(idx+2,digits,dp);
        }
        return dp[idx]=op1+op2;
    }
  public:
    int countWays(string &digits) {
        vector<int>dp(digits.size(),-1);
        return solve(0,digits,dp);
    }
};