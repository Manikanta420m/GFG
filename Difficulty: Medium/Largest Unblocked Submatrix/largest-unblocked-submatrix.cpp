class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        if(k==0)return n*m;
        vector<int>r,c;
        for(auto i:arr){
            r.push_back(i[0]);
            c.push_back(i[1]);
        }
        r.push_back(n+1);
        c.push_back(m+1);
        // r.push_back(1);
        // c.push_back(1);
        sort(r.begin(),r.end());
        sort(c.begin(),c.end());
        int maxx=INT_MIN,maxy=INT_MIN,pre=0;
        for(auto i:r){
            maxx=max(maxx,i-pre-1);
            pre=i;
        }pre=0;
        for(auto i:c){
            maxy=max(maxy,i-pre-1);
            pre=i;
        }
        return maxx*maxy;
    }
};