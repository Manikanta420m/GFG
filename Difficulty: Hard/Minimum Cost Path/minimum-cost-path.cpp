

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool isSafe(int i,int j,int n,int m) {
        if(i>=0 && i<n && j>=0 && j<m) {
            return true;
        }
        return false;
    }
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e8));
        dp[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int cur=p.first;
            int x=p.second.first;
            int y=p.second.second;
            for(int i=0;i<4;i++){
                if(isSafe(x+dx[i],y+dy[i],n,m)){
                    if(dp[x+dx[i]][y+dy[i]]==1e8 or dp[x+dx[i]][y+dy[i]]>cur+grid[x+dx[i]][y+dy[i]]){
                        dp[x+dx[i]][y+dy[i]]=cur+grid[x+dx[i]][y+dy[i]];
                        pq.push({dp[x+dx[i]][y+dy[i]],{x+dx[i],y+dy[i]}});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};