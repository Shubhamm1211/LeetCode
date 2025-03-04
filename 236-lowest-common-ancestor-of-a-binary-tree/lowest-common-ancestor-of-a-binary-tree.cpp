/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root) return NULL;
        if(root == p) return root;;
        if(root == q) return root;
        TreeNode* leftans = solve(root -> left, p,q);
        TreeNode *rightans = solve(root -> right, p,q);
        if(leftans and rightans){
            return root;
        }
        return leftans ? leftans : rightans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return solve(root, p, q); 
    }
};