class Solution {
  public:
  vector<vector<int>>adj;
  int ans=0;
  int solve(int node,int parent,int size){
      priority_queue<int,vector<int>,greater<int>>pq;
      for(auto i:adj[node]){
          if(i!=parent){
              pq.push(solve(i,node,size+1));
          }
          if(pq.size()>2)pq.pop();
      }
      int maxa=0,val=0;
      while(!pq.empty()){
          int temp=pq.top();
          maxa+=temp;
          val=max(val,temp);
          pq.pop();
      }
      ans=max(maxa,ans);
      return val+1;
  }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        adj.resize(V);
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        solve(0,-1,0);
        return ans;
    }
};
