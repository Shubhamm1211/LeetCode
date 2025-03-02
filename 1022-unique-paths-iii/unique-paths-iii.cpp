class Solution {
public:
    int ans;
    int tr,tc;
    int n,m;
    void solve(vector <vector <int>> &grid, int row, int col, int nonobs, int cnt){
        if(row < 0 or col < 0 or row >= n or col >= m) return ;
        if(grid[row][col] == -1 or grid[row][col] == -9) return ;
        if(row == tr and col == tc) {
            if(cnt == nonobs) ans++;
            return;
        }
        int temp = grid[row][col];
        grid[row][col] = -9;
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            solve(grid,nr,nc,nonobs, cnt + 1);
        }
        grid[row][col] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int sr = -1, sc = -1;
        tr = -1, tc = -1;
        int nonobs = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) nonobs++;
                else if(grid[i][j] == 1){
                    sr = i;
                    sc = j;
                }
                else if(grid[i][j] == 2){
                    tr = i;
                    tc = j;
                }
            }
        }
        ans = 0;
        solve(grid,sr,sc,nonobs,0);
        return ans;
    }
};