class Solution {
    vector<vector<int>>res;
  private:
    int dx[8]={1,1,-1,-1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    bool isValid(int x,int y,int n){
        return (x>=0 and y>=0 and x<n and y<n);
    }
    bool solve(int i,int j,int n,int cnt,vector<vector<int>>&ans){
        if(cnt==n*n){
            res=ans;
            return true;
        }
        for(int k=0;k<8;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];  
            if(isValid(nx,ny,n) and ans[nx][ny]==-1){
                ans[nx][ny]=cnt;
                if(solve(nx,ny,n,cnt+1,ans))return true;
                ans[nx][ny]=-1;
            }
        }
        return false;
    }
  public:
    vector<vector<int>> knightTour(int n) {
       vector<vector<int>>ans(n,vector<int>(n,-1));
       int cnt=1;
       ans[0][0]=0;
       res.clear();
       if(solve(0,0,n,cnt,ans))return res;
       return {{-1}};
    }
};