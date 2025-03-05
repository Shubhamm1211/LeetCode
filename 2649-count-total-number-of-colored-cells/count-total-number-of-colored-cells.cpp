#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        vector <ll> dp(n + 1);
        dp[1] = 1;
        for(ll i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + 4*(i - 1);
        }
        return dp[n];
    }
};