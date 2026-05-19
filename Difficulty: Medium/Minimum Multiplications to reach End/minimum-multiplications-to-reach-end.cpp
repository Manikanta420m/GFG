class Solution {
    const int M=1000;
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<int>vis(1000,-1);
        queue<int>q;
        vis[start]=0;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==end)return vis[node];
            for(auto i:arr){
                int x=(node*i)%1000;
                if(vis[x]==-1){
                    vis[x]=vis[node]+1;
                    q.push(x);
                }
            }
        }
        return -1;
    }
};