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
    void solve(int &ans,int l,int r,TreeNode*root){
        if(!root)return;
        ans=max(ans,l);
        ans=max(ans,r);
        solve(ans,r+1,0,root->right);
        solve(ans,0,l+1,root->left);
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        int l=0,r=0;
        solve(ans,l,r,root);
        return ans;
    }
};