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
        int op1 = l + r + 1;
        int op2 = max(l,r) + 1;
        int op3 = 1;
        maxi = max({maxi,op1,op2,op3});
        return max(op2,op3);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxi = INT_MIN;
        solve(root);
        return maxi - 1;
    }
};