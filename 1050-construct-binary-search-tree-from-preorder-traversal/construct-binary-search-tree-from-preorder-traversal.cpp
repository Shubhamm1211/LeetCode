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
    TreeNode *solve(vector <int> &pre, int &ind, int bound){
        if(ind == pre.size() or pre[ind] > bound) return NULL;
        TreeNode *root = new TreeNode(pre[ind]);
        ind++;
        root -> left = solve(pre, ind, root -> val);
        root -> right = solve(pre, ind, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        int bound = INT_MAX;
        return solve(preorder,ind,bound);
    }
};