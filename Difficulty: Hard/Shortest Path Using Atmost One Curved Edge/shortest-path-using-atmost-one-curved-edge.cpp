class Solution {
  public :
    void dijstra(int src,vector<int>&dist,vector<pair<int,int>>adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if (it.first > dist[it.second]) continue;
            for(auto i:adj[it.second]){
                if(it.first+i.second<dist[i.first]){
                    dist[i.first]=it.first+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
    }
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,int>>adj[V];
        vector<pair<pair<int,int>,int>>cur;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
            cur.push_back({{i[0],i[1]},i[3]});
        }
        vector<int>dist1(V,INT_MAX);
        vector<int>dist2(V,INT_MAX);
        dijstra(a,dist1,adj);
        dijstra(b,dist2,adj);
        int ans=dist1[b];
        for(auto i:cur){
            int a=i.first.first;
            int b=i.first.second;
            int wt=i.second;
            int a1=dist1[a];
            int b1=dist1[b];
            int a2=dist2[a];
            int b2=dist2[b];
            if(a1!=INT_MAX and b2!=INT_MAX){
                ans=min(ans,a1+b2+wt);
            }
            if(a2!=INT_MAX and b1!=INT_MAX){
                ans=min(ans,a2+b1+wt);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};