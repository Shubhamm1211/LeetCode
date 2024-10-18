class Solution {
public:
    int solve(int row, int col, vector<vector<int>> &mat, vector <vector<int>> &dp){
        int n = mat.size();
        if(row == n - 1){
            return mat[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        int right =  solve(row + 1, col, mat,dp);
        int digdown =  solve(row + 1, col + 1, mat,dp);

        return dp[row][col] = mat[row][col] + min(right,digdown);
    }
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector<int>> dp(n + 1, vector<int>(n + 1,-1));
        return solve(0, 0, mat,dp);
    }
};