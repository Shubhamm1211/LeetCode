class Solution {
public:
    int solve(int ind,vector<int>&coins,int amt,vector<vector<int>>&dp){
        if(ind==0){
            if(amt%coins[0]==0)return amt/coins[0];
            else return 1e9;
        }
        if(ind<0)return 1e9;
        if(dp[ind][amt]!=INT_MIN)return dp[ind][amt];
        int notpick=solve(ind-1,coins,amt,dp);
        int pick=1e9;
        if(coins[ind]<=amt){
            pick= 1+solve(ind,coins,amt-coins[ind],dp);
        }
        return dp[ind][amt]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amt+1,INT_MIN));
        int ans=solve(n-1,coins,amt,dp);
        if(ans==1e9)return -1;
        else return ans;
    }
};