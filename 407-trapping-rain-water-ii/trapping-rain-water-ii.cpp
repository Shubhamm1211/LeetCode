class Solution {
public:
    int trapRainWater(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int r = 0; r < n; ++r) {
            pq.push({v[r][0], {r, 0}});
            vis[r][0] = true;
            pq.push({v[r][m - 1], {r, m - 1}});
            vis[r][m - 1] = true;
        }
        for (int c = 0; c < m; ++c) {
            pq.push({v[0][c], {0, c}});
            vis[0][c] = true;
            pq.push({v[n - 1][c], {n - 1, c}});
            vis[n - 1][c] = true;
        }
        int ans = 0;
        while (!pq.empty()) {
            int h = pq.top().first;
            pair <int,int> temp = pq.top().second;
            pq.pop();
            int r = temp.first;
            int c = temp.second;
            for (auto &dir : dir) {
                int nrow = r + dir[0];
                int ncol = c + dir[1];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol]) {
                    ans += max(0, h - v[nrow][ncol]);
                    pq.push({max(h, v[nrow][ncol]), {nrow, ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return ans;
    }
};
