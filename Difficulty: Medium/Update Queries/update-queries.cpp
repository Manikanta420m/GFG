// User function Template for C++

class Solution {
  public:
    vector<int> updateQuery(int n, int Q, vector<vector<int>> &U) {
        // code here
        vector<vector<int>>bittu(32,vector<int>(n+1,0));
        for(auto i:U){
            int l=i[0],r=i[1],x=i[2];
            l--,r--;
            for(int j=0;j<32;j++){
                if(x&(1<<j)){
                    bittu[j][l]++;
                    bittu[j][r+1]--;
                }
            }
        }
        for(int j=0;j<32;j++){
            for(int i=1;i<n;i++){
                bittu[j][i]+=bittu[j][i-1];
            }
        }
        vector<int>ans(n);
        for(int j=0;j<32;j++){
            for(int i=0;i<n;i++){
                if(bittu[j][i]!=0){
                    ans[i]|=(1<<j);
                }
            }
        }
        return ans;
    }
};