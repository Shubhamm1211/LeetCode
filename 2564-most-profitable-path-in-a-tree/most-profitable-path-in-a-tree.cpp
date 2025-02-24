class Solution {
public:
    bool dfs(int bob, vector<vector<int>> &adj, int cnt, vector<int> &vis, map<int,int> &mp) {
        vis[bob] = 1;
        mp[bob] = cnt;
        cnt++;
        if (bob == 0) return true;
        for (auto x : adj[bob]) {
            if (!vis[x]) {
                if (dfs(x, adj, cnt, vis, mp)) {
                    return true;
                }
            }
        }
        mp.erase(bob);
        return false;
    }

    void dfs2(int node, vector<vector<int>> &adj, int cnt, vector<int> &vis,
               map<int,int> &mp, int ans, int &maxi, vector<int> &amount) {
        vis[node] = 1;
        if (mp.find(node) == mp.end()) {
            ans += amount[node];
        } 
        else if (mp[node] > cnt) {
            ans += amount[node];
        } 
        else if (mp[node] == cnt) {
            ans += amount[node] / 2;
        }

        if (adj[node].size() == 1 && node != 0) {
            maxi = max(maxi, ans);
        }
        for (auto x : adj[node]) {
            if (!vis[x]) {
                dfs2(x, adj, cnt + 1, vis, mp, ans, maxi, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto vec : edges) {
            int x = vec[0];
            int y = vec[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        map<int, int> mp;
        mp[bob] = 0;
        int cnt = 0;
        vector<int> vis(n, 0);
        dfs(bob, adj, cnt, vis, mp);
        int ans = 0;
        vis.assign(n, 0);
        cnt = 0;
        int maxi = INT_MIN;
        dfs2(0, adj, cnt, vis, mp, ans, maxi, amount);
        return maxi;
    }
};
