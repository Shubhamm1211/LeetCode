class Solution {
public:
    bool solve(int ind1, int ind2, string &s1, string &s2, vector <vector <int>> &dp){
        if(ind1 < 0 and ind2 < 0) return true;
        if(ind1 < 0 and ind2 >= 0){
            for(int i = ind2; i >= 0; i--){
                if(s2[i] != '*') return false;
            }
            return true;
        }
        if(ind1 >= 0 and ind2 < 0) return false;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2] or s2[ind2] == '?'){
            return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s1, s2, dp);
        }
        if(s2[ind2] == '*') return dp[ind1][ind2] = (solve(ind1 - 1, ind2, s1, s2,dp) or solve(ind1, ind2 - 1, s1, s2,dp));
        return dp[ind1][ind2] = false;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector <vector <int>> dp(n1, vector<int>(n2 + 1, -1));
        return solve(n1 - 1, n2 - 1,s ,p, dp);
    }
};