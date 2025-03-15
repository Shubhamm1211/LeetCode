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
    TreeNode *prev, *first, *middle, *last;
    void inorder(TreeNode *root){
        if(!root) return;
        if(root -> left){
            inorder(root -> left);
        }
        if(prev and prev -> val > root -> val){
            if(!first){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        prev = NULL, first = NULL, middle = NULL, last = NULL;
        inorder(root);
        if(!last and first and middle){
            swap(first -> val ,middle -> val);
        }
        else if(first and last){
            swap(first -> val, last -> val);
        }
    }
};