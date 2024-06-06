class Solution {
public:
    int solve(vector<vector<int>>& arr,int r,int c,vector<vector<int>>&dp){
        int n=arr.size();
        if(r==n-1)return arr[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        int down=solve(arr,r+1,c,dp);
        int diag=solve(arr,r+1,c+1,dp);
        return dp[r][c]=arr[r][c]+min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(arr,0,0,dp);
    }
};