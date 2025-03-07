class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tot = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        tot += grid[row][col];
        grid[row][col] = 0; 
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] != 0) {
                    tot += grid[nr][nc];
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        
        return tot;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) { 
                    maxi = max(maxi, bfs(i, j, grid));
                }
            }
        }
        return maxi;
    }
};
