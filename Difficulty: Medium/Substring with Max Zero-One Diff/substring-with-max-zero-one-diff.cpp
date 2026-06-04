class Solution {
  public:
    virtual int maxSubstring(string &s){
      int c0=0, c1=0;
      
      int ans=-1;
      for(char ch: s){
        if(ch=='1') c1++;
        else c0++;
        
        int dif=c0-c1;
        ans=max(ans, dif);
        
        if(dif<0) { c0=0; c1=0; }
        
      }
      
      return ans;
    }
};