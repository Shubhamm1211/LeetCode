class Solution {
public:
    int solve(vector <int> &coins, int ind, int amt, vector <vector<int>>&dp){
        if(ind < 0) return 1e5;
        if(ind == 0){
            if(amt % coins[ind] == 0){
                return amt / coins[0];
            }
            else return 1e5;
        }
        if(dp[ind][amt] != -1) return dp[ind][amt];
        int pick = 1e5;
        if(amt - coins[ind] >= 0){
            pick = 1 + solve(coins,ind , amt - coins[ind],dp);
        }
        int notpick = solve(coins, ind - 1, amt,dp);
        int ans = min(pick,notpick);
        return dp[ind][amt] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <vector<int>> dp(n + 1 ,vector<int>(amount + 1, -1));
        int ans = solve(coins, n - 1, amount,dp);
        if(ans == 1e5){
            return -1;
        }
        return ans;
    }
};