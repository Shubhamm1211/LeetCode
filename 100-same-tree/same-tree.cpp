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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and q or !q and p) return false;
        if(!p and !q) return true;
        if(p -> val != q -> val) return false;
        bool check1 = isSameTree(p -> right, q -> right);
        bool check2 = isSameTree(p -> left, q -> left);
        return (check1 and check2);
    }
};