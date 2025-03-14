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
    int maxi;
    int solve(TreeNode *root){
        if(!root) return 0;
        int l = solve(root -> left);
        int r = solve(root -> right);
        int op1 = root -> val + l + r;
        int op2 = max(l,r) + root -> val;
        int op3 = root -> val;
        maxi = max({maxi,op1,op2,op3});
        return max(op2,op3);
    }
    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        solve(root);
        return maxi;
    }
};