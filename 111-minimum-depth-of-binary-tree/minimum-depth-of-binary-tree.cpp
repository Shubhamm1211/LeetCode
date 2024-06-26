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
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left==NULL and root->right==NULL)return 1;
        
        int mini=INT_MAX;
        if(root->right){
            mini= min(minDepth(root->right),mini);
        }
        if(root->left){
             mini=min(minDepth(root->left),mini);
        }
        return mini+1;
        
    }
};