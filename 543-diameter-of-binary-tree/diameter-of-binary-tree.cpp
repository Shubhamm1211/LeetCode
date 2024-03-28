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
    int height(int &d,TreeNode*root){
        if(root==NULL)return 0;
        int rh=height(d,root->right);
        int lh=height(d,root->left);
        d=max(d,lh+rh);
        return 1+max(rh,lh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        int ans=height(d,root);
        return d;
    }
};