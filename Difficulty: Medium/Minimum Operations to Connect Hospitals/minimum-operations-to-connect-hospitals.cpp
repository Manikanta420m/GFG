class Solution {
  private:
    void dfs(int u,vector<bool>&vis,vector<int>adj[]){
        if(vis[u])return;
        vis[u]=true;
        for(auto v:adj[u]){
            if(!vis[v])dfs(v,vis,adj);
        }
    }
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        int ans=0;
        int E=edges.size();
        if(V-1>E)return -1;
        vector<int>adj[V];
        vector<bool>vis(V);
        for(auto i:edges){
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans-1;
    }
};
