class Solution {
public:
    int solve(int ind1, int ind2, string s1, string s2, vector <vector<int>> &dp){
        if(ind1 < 0 or ind2 < 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]){
            return 1 + solve(ind1 - 1, ind2 - 1, s1, s2,dp);
        }
        int op1 = solve(ind1 - 1, ind2, s1, s2, dp);
        int op2 = solve(ind1, ind2 - 1, s1, s2, dp);
        return dp[ind1][ind2] = max(op1,op2);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int lcs = solve(n - 1, m - 1, word1, word2, dp);
        int ans = n - lcs + m - lcs;
        return ans;
    }
};