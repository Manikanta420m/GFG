class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int n=edges.size();
        return (V*(V-1)/2)-n;
    }
};
