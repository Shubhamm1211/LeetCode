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
    int calcright(TreeNode *root){
        int ans = 1;
        while(root -> right){
            ans++;
            root = root -> right;
        }
        return ans;
    }
    int calcleft(TreeNode *root){
        int ans = 1;
        while(root -> left){
            ans++;
            root = root -> left;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int rh = calcright(root);
        int lh = calcleft(root);
        if(rh == lh){
            return (1 << rh) - 1;
        }
        return countNodes(root -> right) + countNodes(root -> left) + 1;
    }
};