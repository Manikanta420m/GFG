class Solution {
  private:
    bool solve(int n,int m,int siz,string &s1, string &s2, string &s3){
        if(n==0 and m==0 and siz==0)return true;
        if((n>0 and m>0) and (s2[m-1]==s3[siz-1] and s1[n-1]==s3[siz-1]))
           return solve(n,m-1,siz-1,s1,s2,s3) or solve(n-1,m,siz-1,s1,s2,s3);
        else if(n>0 and s1[n-1]==s3[siz-1])return solve(n-1,m,siz-1,s1,s2,s3);
        else if(m>0 and s2[m-1]==s3[siz-1])return solve(n,m-1,siz-1,s1,s2,s3);
        else return false;
    }
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n=s1.size();
        int m=s2.size();
        int siz=s3.size();
        if(n+m!=siz)return false;
        return solve(n,m,siz,s1,s2,s3);
    }
};