/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long
class Solution {
public:
    bool check(TreeNode *root, ll lb, ll ub){
        if(!root) return true;
        if(root -> val <= lb or root -> val >= ub) return false;
        else if(check(root -> right,root -> val, ub) and check(root -> left, lb, root -> val)) return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        ll ub = 2147483648;
        ll lb = -2147483649;
        return check(root,lb,ub);
    }
};