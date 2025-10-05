class Solution {
  public:
    int n,m;
    vector<string> ratInMaze(vector<vector<int>>& maze) {
       n=maze.size(),m=maze[0].size();
       vector<string>ans;
       if(maze[0][0]==0 or maze[n-1][n-1]==0)return ans;
       vector<vector<int>>vis(n,vector<int>(n,0));
       vis[0][0]=1;
       string temp="";
       solve(0,0,maze,ans,temp,vis);
       sort(ans.begin(),ans.end());
       return ans;
    }
    void solve(int i,int j,vector<vector<int>>& maze,vector<string>&ans,string &temp,vector<vector<int>>&vis){
        if(i==n-1 and j==n-1){
            ans.push_back(temp);
            return;
        }
        if(i<n-1 and maze[i+1][j]!=0 and !vis[i+1][j]){
            vis[i+1][j]=1;
            temp+="D";
            solve(i+1,j,maze,ans,temp,vis);
            temp.pop_back();
            vis[i+1][j]=0;
        }
        if(j<m-1 and maze[i][j+1]!=0 and !vis[i][j+1]){
            vis[i][j+1]=1;
            temp+="R";
            solve(i,j+1,maze,ans,temp,vis);
            temp.pop_back();
            vis[i][j+1]=0;
        }
        if(i>0 and maze[i-1][j]!=0 and !vis[i-1][j]){
            vis[i-1][j]=1;
            temp+="U";
            solve(i-1,j,maze,ans,temp,vis);
            temp.pop_back();
            vis[i-1][j]=0;
        }
        if(j>0 and maze[i][j-1]!=0 and !vis[i][j-1]){
            vis[i][j-1]=1;
            temp+="L";
            solve(i,j-1,maze,ans,temp,vis);
            temp.pop_back();
            vis[i][j-1]=0;
        }
        return;
    }
};