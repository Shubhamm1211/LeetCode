class Solution {
public:
    int h[100001];
    int maxi = 0;
    void solve1(TreeNode* node, int curr) {
        if (node == nullptr) return;
        h[node->val] = maxi;
        maxi = max(maxi, curr);
        solve1(node->left, curr + 1);
        solve1(node->right, curr + 1);
    }
    void solve2(TreeNode* node, int curr) {
        if (node == nullptr) return;
        h[node->val] = max(h[node->val], maxi);
        maxi = max(curr, maxi);
        solve2(node->right, curr + 1);
        solve2(node->left, curr + 1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        solve1(root, 0);
        maxi = 0;  
        solve2(root, 0);
        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = h[queries[i]];
        }
        return queryResults;
    }
};