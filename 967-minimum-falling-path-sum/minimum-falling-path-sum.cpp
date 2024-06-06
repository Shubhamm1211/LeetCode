class Solution {
public:
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        int n = mat.size();
        if (j < 0 || j >= n) return INT_MAX;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        if (i == 0) return mat[i][j];

        int up = mat[i][j] + solve(mat, i - 1, j, dp);
        int rdg = (j + 1 < n) ? mat[i][j] + solve(mat, i - 1, j + 1, dp) : INT_MAX;
        int ldg = (j - 1 >= 0) ? mat[i][j] + solve(mat, i - 1, j - 1, dp) : INT_MAX;
        
        return dp[i][j] = min(up, min(ldg, rdg));
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for (int i = 0; i < n; i++) {
            mini = min(mini, solve(mat, n - 1, i, dp));
        }
        
        return mini;
    }
};
