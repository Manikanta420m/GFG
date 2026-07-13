class Solution {
    const int M=1e9+7;
  public:
    int minOperations(vector<int> &b) {
        // code here
        int n=b.size(),ans=1;
        vector<bool>vis(n+1,false);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cyc=0;
                int cur=i;
                while(!vis[cur]){
                    vis[cur]=true;
                    cur=b[cur-1];
                    cyc++;
                }
                int g=__gcd(ans,cyc);
                ans=(ans/g)*cyc;
            }
        }
        return ans%M;
    }
};