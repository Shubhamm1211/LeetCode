class Solution {
public:
    int solve(int ind,int buy,vector<int>&p,int n,vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-p[ind]+solve(ind+1,0,p,n,dp),solve(ind+1,1,p,n,dp));
        }
        else{
            profit=max(p[ind]+solve(ind+1,1,p,n,dp),solve(ind+1,0,p,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,p,n,dp);
    }
};