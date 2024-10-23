class Solution {
public:
    int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp){
        if(ind1 < 0 ) return ind2 + 1;
        if(ind2 < 0) return ind1 + 1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s1, s2,dp);
        }
        else{
            int a = solve(ind1 - 1, ind2, s1, s2,dp);
            int b = solve(ind1, ind2 - 1, s1, s2,dp);
            int c = solve(ind1 - 1, ind2 - 1, s1, s2,dp);
            return dp[ind1][ind2] = 1 + min({a,b,c});
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1 ,vector<int>(n2 ,-1));
        return solve(n1 - 1, n2 - 1, word1, word2,dp);    
    }
};