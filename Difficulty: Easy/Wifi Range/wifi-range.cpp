class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n=s.size();
        int mini=-1,maxi=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                maxi=i+x;
                if(i-x-1<=mini)mini=maxi;
                else return false;
            }
        }
        return maxi>=n-1;
    }
};