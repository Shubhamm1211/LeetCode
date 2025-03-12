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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        TreeNode *curr = root;
        int cnt = 0;
        int ans = INT_MIN;
        while(curr){
            if(!curr -> left){
                cnt++;
                if(cnt == k) ans = curr -> val;
                curr = curr -> right;
            }
            else{
                TreeNode *prev = curr -> left;
                while(prev -> right and prev -> right != curr){
                    prev = prev -> right;
                }
                if(!prev -> right){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                else{
                    cnt++;
                    if(cnt == k) ans = curr -> val;
                    prev -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};