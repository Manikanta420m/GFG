class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int ans=0;
        int n=a.size();
        vector<int>idx(n);
        for(int i=0;i<n;i++)idx[i]=i;
        sort(idx.begin(),idx.end(),[&](int i,int j){
           return abs(a[i]-b[i])>abs(a[j]-b[j]); 
        });
        for(int i:idx){
            if((a[i]>=b[i] and x>0) || y==0){
                ans+=a[i];
                x--;
            }
            else {
                ans+=b[i];
                y--;
            }
        }
        return ans;
    }
};