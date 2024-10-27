class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();
        if(i >= n or i < 0 or j >= m or j < 0) return 0;
        if(mat[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(i, j + 1, mat, dp);
        int down = solve(i + 1, j, mat, dp);
        int dig = solve(i + 1, j + 1, mat, dp);
        return dp[i][j] = 1 + min({right,down,dig});
    }

    int countSquares(vector<vector<int>>& mat) {
        int ans = 0;
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                ans += solve(i, j, mat, dp);
            }
        }
        return ans;
    }
};