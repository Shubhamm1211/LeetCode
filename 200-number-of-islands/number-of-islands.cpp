class Solution {
public:
    int n,m;
    void dfs(int row, int col, vector <vector<char>> &grid, vector <vector <int>> &vis){
        vis[row][col] = 1;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == '1' and !vis[nr][nc]){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        vector <vector <int>> vis(n,vector <int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};