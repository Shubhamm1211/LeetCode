class Solution {
public:
    int solve(int amt, vector<int> &coins, int ind,vector <vector<int>> &dp){
        if(amt == 0){
            return 1;
        }
        if(ind == 0){
            if(amt % coins[0] == 0 or amt == 0){
                return 1;
            }
            else return 0;
        }
        if(dp[ind][amt] != -1){
            return dp[ind][amt];
        }
        int pick = 0;
        if(coins[ind] <= amt){
            pick = solve(amt - coins[ind], coins, ind,dp);
        }
        int notpick = solve(amt,coins,ind - 1,dp);

        return dp[ind][amt] = pick + notpick ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector <vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(amount, coins, n - 1,dp);
    }
};