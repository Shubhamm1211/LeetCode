class Solution {
private:
    int dfs1(int node, int parent, vector<int> adj[], vector<int>& dp, vector<int>& ans) {
        int sum = 0;
        int val = 0;
        for (auto it : adj[node]) {
            if (it != parent) {
                sum += dfs1(it, node, adj, dp, ans);
                val += ans[it];
            }
        }
        ans[node] = sum + val;
        return dp[node] = sum + 1;
    }

    void dfs2(int node, int parent, vector<int> adj[], vector<int>& dp, vector<int>& ans, int n) {
        for (auto it : adj[node]) {
            if (it != parent) {
                ans[it] += ans[node] - (ans[it] + dp[it]) + (n - dp[it]);
                dfs2(it, node, adj, dp, ans, n);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(n, 0);
        vector<int> dp(n, 0);
        dfs1(0, -1, adj, dp, ans);
        dfs2(0, -1, adj, dp, ans, n);
        return ans;
    }
};
