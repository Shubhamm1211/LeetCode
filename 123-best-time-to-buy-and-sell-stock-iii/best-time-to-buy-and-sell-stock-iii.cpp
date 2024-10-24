class Solution {
public:
    int solve(int ind, int buy, vector<int> &price, int trans,vector<vector<vector<int>>> &dp){
        int n = price.size();
        if(ind == n){
            return 0;
        }
        if(trans == 0){
            return 0;
        }
        if(dp[ind][buy][trans] != -1){
            return dp[ind][buy][trans];
        }
        int pro = 0;
        if(buy){
            pro = max(-price[ind] + solve(ind + 1, 0, price, trans,dp), solve(ind + 1, 1, price, trans, dp));
        }
        else{
            pro = max(price[ind] + solve(ind + 1, 1, price, trans - 1,dp), solve(ind + 1, 0, price, trans, dp));
        }
        return dp[ind][buy][trans] = pro;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(3, -1)));
        return solve(0,1,prices,2,dp);
    }
};