class Solution {
public:
    bool inorder(TreeNode* root, int v) {
        if (root==NULL)return true;
        if (inorder(root->left, v)==false) return false; 
        if (root->val!=v) return false;
        return inorder(root->right, v); 
    }

    bool isUnivalTree(TreeNode* root) {
        if (root==NULL)return true; 
        return inorder(root, root->val);
    }
};
