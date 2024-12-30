#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    int solve(int len, int mini, int maxi, int l1, int l2,  vector <int> &dp){
        if(len > maxi) return 0;
        if(dp[len] != -1) return dp[len];
        bool f = false;
        if(len >= mini and len <= maxi) f = true;
        int p1 = solve(len + l1, mini, maxi, l1, l2, dp);
        int p2 = solve(len + l2, mini, maxi, l1, l2, dp);
        return dp[len] = (f + p1 + p2) % mod;
    }
    int countGoodStrings(int low, int high, int l1, int l2) {
        int len = 0;
        vector <int> dp(high + 1, -1);
        return solve(len,low,high,l1,l2, dp);
    }
};