class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        const int M=1e9+7;
        int ans=0;
        vector<int>vis(26,-1);
        for(int i=0;i<str.size();i++){
            int idx=str[i]-'a',cur;
            if(i==0){
                cur=1;
                ans=1;
            }
            else{
                if(vis[idx]==-1){
                    cur=1+ans;
                    ans=(ans+cur)%M;
                }
                else{
                    cur=1+ans;
                    ans=((ans+cur)%M-(vis[idx])%M)%M;
                }
            }
            vis[idx]=cur;
        }
        return (ans+1+M)%M;
    }
};