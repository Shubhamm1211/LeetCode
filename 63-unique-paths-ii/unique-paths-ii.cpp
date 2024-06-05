class Solution {
public:
    int solve(vector<vector<int>>&arr,int row,int col,vector<vector<int>>&dp){
        if(row>=0 && col>=0 && arr[row][col]==1)return 0;
        if(row<0 || col<0)return 0;
        if(row==0 && col==0)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int up=solve(arr,row-1,col,dp);
        int left=solve(arr,row,col-1,dp);
        return dp[row][col]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(arr,n-1,m-1,dp);
    }
};