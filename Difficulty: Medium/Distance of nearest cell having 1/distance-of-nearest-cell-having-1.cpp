class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        // Step 1: push all cells with 1 into the queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Step 2: BFS traversal
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};
