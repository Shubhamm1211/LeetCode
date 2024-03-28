class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==NULL) {
            return false;
        }
        if (root->left==NULL && root->right==NULL) {
            return targetSum == root->val;
        }
        bool l= hasPathSum(root->left, targetSum - root->val);
        bool r = hasPathSum(root->right, targetSum - root->val);
        
        return l || r;
    }
};