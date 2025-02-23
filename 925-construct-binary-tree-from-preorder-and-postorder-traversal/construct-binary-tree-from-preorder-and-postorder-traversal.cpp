/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& pre, vector<int>& post, int& i, int start, int end, map<int, int>& mp) {
        if (i >= pre.size() || start > end) return nullptr;
        TreeNode* root = new TreeNode(pre[i++]);
        if (start == end) return root; 
        int left = pre[i];
        int ind = mp[left];
        root->left = solve(pre, post, i, start, ind, mp);
        root->right = solve(pre, post, i, ind + 1, end - 1, mp);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int i = 0;
        map<int, int> mp;
        for (int j = 0; j < post.size(); j++) {
            mp[post[j]] = j;
        }
        return solve(pre, post, i, 0, post.size() - 1, mp);
    }
};
