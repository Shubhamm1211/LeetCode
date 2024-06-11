class Solution {
public:
int solve(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (text1[ind1] == text2[ind2])
    {
        return dp[ind1][ind2] = 1 + solve(text1, text2, ind1 - 1, ind2 - 1, dp);
    }
    return dp[ind1][ind2] = max(solve(text1, text2, ind1 - 1, ind2, dp), solve(text1, text2, ind1, ind2 - 1, dp));
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        int lcs=solve(word1,word2,n-1,m-1,dp);
        int ans=n-lcs+m-lcs;
        return ans;
    }
};