class Solution {
public:
    int solve(vector<int>&cost,int ind,vector<int>&dp){
        int n=cost.size();
        if(ind<=1)return cost[ind];
        if(dp[ind]!=-1)return dp[ind];
        int step1=cost[ind]+solve(cost,ind-1,dp);
        int step2=INT_MAX;
        if(ind>1){
            step2=cost[ind]+solve(cost,ind-2,dp);
        }
        return dp[ind]=min(step1,step2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    }
};