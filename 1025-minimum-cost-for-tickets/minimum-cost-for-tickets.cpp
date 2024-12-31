class Solution {
public:
    int solve(int n1, vector <int> & days, vector <int>& costs, int ind, vector <int>&dp) {
        if (ind >= n1) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int op1 = costs[0] + solve(n1, days, costs, ind + 1, dp);
        int i;
        for (i = ind; i < n1 && days[i] < days[ind] + 7; i++);
        int op2 = costs[1] + solve(n1, days, costs, i, dp);

        for (i = ind; i < n1 && days[i] < days[ind] + 30; i++);
        int op3 = costs[2] + solve(n1, days, costs, i, dp);

        dp[ind] = min(op1, min(op2, op3));
        return dp[ind];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return solve(n, days, costs, 0, dp);
    }
};