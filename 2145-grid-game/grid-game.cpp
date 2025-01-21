#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll n = 2;
        ll m = grid[0].size();
        ll mini = LONG_LONG_MAX;
        ll fr = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        ll sr = 0;
        for(ll i = 0; i < m; i++){
            fr -= grid[0][i];
            ll temp = max(fr,sr);
            mini = min(mini,temp);
            sr += grid[1][i];
        }
        return mini;
    }
};