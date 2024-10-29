class Solution {
public:
    int solve(int row, int col, vector<vector<int>> &grid, int curr, vector <vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(row >= n or row < 0 or col >= m or col < 0) return 0;
        if(grid[row][col] <= curr) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int op1 = solve(row - 1, col + 1, grid, grid[row][col],dp);
        int op2 = solve(row, col + 1, grid, grid[row][col],dp);
        int op3 = solve(row + 1, col + 1, grid, grid[row][col],dp);
        return dp[row][col] = 1 + max({op1, op2, op3});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector <vector<int>> dp(n + 1 , vector<int>(m + 1, -1));
        for(int i = 0; i < n; i++){
            ans = max(ans, solve(i,0,grid,-1e5,dp));
        }
        return ans - 1;
    }
};