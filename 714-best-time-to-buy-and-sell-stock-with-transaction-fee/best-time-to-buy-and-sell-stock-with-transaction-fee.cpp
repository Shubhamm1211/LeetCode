class Solution {
public:

    int solve(vector <int> &p, int ind, int buy, vector<vector<int>> &dp, int fee){
        int n = p.size();
        int pro = 0;
        if(ind >= n){
            return pro;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            pro = max(-p[ind] + solve(p,ind + 1,0,dp, fee), solve(p,ind + 1, 1,dp, fee));
        }
        else{
            pro = max(p[ind] + solve(p,ind + 1,1,dp, fee) - fee, solve(p,ind + 1, 0,dp, fee));
        }
        return dp[ind][buy] = pro;
    }
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>>dp(n + 1,vector<int>(2, -1));
        return solve(p,0,1,dp, fee);
    }
};