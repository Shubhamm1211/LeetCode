class Solution {
public:
    int dfs(int row, int col, vector <vector <int>> &grid, vector <vector<int>> &vis, int id){
        vis[row][col] = 1;
        grid[row][col] = id;
        int n = grid.size();
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        int size = 1;
        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 and nr < n and nc >= 0 and nc < n and !vis[nr][nc] and grid[nr][nc] == 1){
                size += dfs(nr, nc, grid, vis, id);
            }
            // else return 0;
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <vector <int>> vis(n,vector <int>(n,0));
        int id = 2;
        int maxi = 0;
        map <int,int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    int size = dfs(i,j,grid,vis,id);
                    mp[id] = size;
                    maxi = max(maxi,size);
                    id++;
                }
            }
        }
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    set <int> st;
                    for(int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr >= 0 and nr < n and nc >= 0 and nc < n and grid[nr][nc] != 0){
                            st.insert(grid[nr][nc]);
                        }
                    }
                    int sum = 1;
                    for(auto &x : st){
                        sum += mp[x];
                    }
                    maxi = max(maxi,sum);
                }
            }
        }
        return maxi;
    }
};