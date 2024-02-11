class Solution {
public:
    int helper(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int m = grid[0].size();
        int n = grid.size();
        
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return 0;
        
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        int maxi = 0;
        for (int k = -1; k < 2; k++) {
            for (int h = -1; h < 2; h++) {
                if (j1 == j2)
                    maxi = max(maxi, (grid[i][j1] + helper(i + 1, j1 + k, j2 + h, grid, dp)));
                else
                    maxi = max(maxi , (grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + k, j2 + h, grid, dp)));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size(); 
        int n = grid.size();    
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        int ans = helper(0, 0, m - 1, grid, dp);
        return ans;
    }
};
