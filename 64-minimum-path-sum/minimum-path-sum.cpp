class Solution {
public:
    int solve(int row, int col, vector<vector<int>>&grid, vector <vector<int>> &dp){
        if(row == 0 and col == 0){
            return grid[row][col];
        }
        if(row < 0 or col < 0){
            return 201 * 200 * 200;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int up = grid[row][col] + solve(row - 1, col, grid,dp);
        int left = grid[row][col] + solve(row, col - 1, grid,dp);

        return dp[row][col] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, grid,dp);
    }
};