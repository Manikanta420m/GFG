class Solution {
    int n;
    bool check(int x,int y){
        return x>0 and x<=n and y>0 and y<=n;
    }
    int dx[8]={1,1,-1,-1,2,-2,2,-2};
    int dy[8]={2,-2,2,-2,1,1,-1,-1};
  public:
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Code here
        int lvl=0;
        n=N;
        int x=KnightPos[0],y=KnightPos[1];
        int tx=TargetPos[0],ty=TargetPos[1];
        if(x==tx and y==ty)return 0;
        vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty()){
            int m=q.size();
            for(int j=0;j<m;j++){
                auto node=q.front();
                q.pop();
                int px=node.first,py=node.second;
                for(int i=0;i<8;i++){
                    int nx=px+dx[i];
                    int ny=py+dy[i];
                    if(!check(nx,ny))continue;
                    if(nx==tx and ny==ty)return lvl+1;
                    if(!vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};