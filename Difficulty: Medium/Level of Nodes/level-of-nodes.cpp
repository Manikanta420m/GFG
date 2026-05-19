
class Solution {
  public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X) {
        if(X==0)return 0;
        int lvl=0;
        queue<int>q;
        q.push(0);
        vector<int>vis(V+1,0);
        while(!q.empty()){
            int n=q.size();
            for(int j=0;j<n;j++){
                int node=q.front();
                q.pop();
                for(auto i:adj[node]){
                    if(i==X)return lvl+1;
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};