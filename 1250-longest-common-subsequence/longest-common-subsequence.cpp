class Solution {
public:
    int solve(int ind1, int ind2, string &s1, string &s2, vector <vector<int>> &dp){
        if(ind1 < 0 or ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]){
            return 1 + solve(ind1 - 1, ind2 - 1, s1, s2,dp);
        }
        int p1 = solve(ind1 - 1, ind2, s1, s2,dp);
        int p2 = solve(ind1, ind2 - 1, s1, s2,dp);

        return dp[ind1][ind2] = max(p1,p2);
    }
    int longestCommonSubsequence(string s1, string s2) {
        int ind1 = s1.size();
        int ind2 = s2.size();
        vector <vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
        return solve(ind1 - 1, ind2 - 1, s1, s2,dp);
    }
};