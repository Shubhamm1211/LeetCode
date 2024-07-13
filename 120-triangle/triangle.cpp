class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&v,vector<vector<int>>&dp){
        int n=v.size();
        if(i==n-1)return v[n-1][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int down=v[i][j]+solve(i+1,j,v,dp);
        int dig=v[i][j]+solve(i+1,j+1,v,dp);
        return dp[i][j]=min(down,dig);
    }
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,v,dp);
    }
};