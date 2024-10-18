class Solution {
public:
    int solve(int row, int col, vector <vector<int>> &mat,vector <vector<int>> &dp){
        if(row == 0 and col == 0){
            if(mat[row][col] == 1){
                return 0;
            }
            else return 1;
        }
        if(row < 0 or col < 0){
            return 0;
        }
        if(mat[row][col] == 1){
            return 0;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int up = solve(row - 1, col, mat,dp);
        int left = solve(row, col - 1, mat,dp);

        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, mat,dp);
    }
};