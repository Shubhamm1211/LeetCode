class Solution {
public:
    int solve(int ind,int next,vector<int>&prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind][next]!=-1)return dp[ind][next];
        int pick=prices[ind]+solve(ind+1,ind+1,prices,dp);
        int npick=INT_MAX;
        if(next>0){
            npick=solve(ind+1,next-1,prices,dp);
        }
        return dp[ind][next]=min(pick,npick);
    }
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, 0, prices, dp);
    }
    
};
