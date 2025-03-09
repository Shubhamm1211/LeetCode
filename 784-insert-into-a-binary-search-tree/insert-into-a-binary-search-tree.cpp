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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode *temp = new TreeNode(val);
            return temp;
        }
        TreeNode *temp = root;
        TreeNode *prev;
        while(temp){
            if(val > temp -> val){
                prev = temp;
                temp = temp -> right;
            }
            else{
                prev = temp;
                temp = temp -> left;
            }
        }
        if(val > prev -> val){
            prev -> right = new TreeNode(val);
        }
        if(val < prev -> val){
            prev -> left = new TreeNode(val);
        }
        return root;
    }
};