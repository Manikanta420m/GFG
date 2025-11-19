class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>a(n,vector<int>(m,1e9));
        a[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            int x=ele.second.first;
            int y=ele.second.second;
            if(x==n-1 and y==m-1)return ele.first;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<m){
                    int cur=abs(mat[nx][ny]-mat[x][y]);
                    if(max(cur,ele.first)<a[nx][ny]){
                        a[nx][ny]=max(cur,ele.first);
                        pq.push({a[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};
