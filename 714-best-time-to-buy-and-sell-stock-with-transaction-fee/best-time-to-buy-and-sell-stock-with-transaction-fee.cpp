class Solution {
public:
    int solve(int ind,int buy,vector<int>&price,int fee,vector<vector<int>>&dp){
        if(ind==price.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-price[ind]+solve(ind+1,0,price,fee,dp),
                        0+solve(ind+1,1,price,fee,dp));
        }
        else{
            profit=max(price[ind]+solve(ind+1,1,price,fee,dp)-fee,
                        0+solve(ind+1,0,price,fee,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
    }
};