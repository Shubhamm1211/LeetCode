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
    TreeNode *solve(vector <int> &pre, vector <int> &in, unordered_map <int,int> &mp, int start, int end, int &ind){
        if(start > end){
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[ind]);
        int temp = mp[pre[ind]];
        ind++;
        root -> left = solve(pre, in, mp, start, temp - 1, ind);
        root -> right = solve(pre, in, mp, temp + 1, end, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int ind = 0;
        unordered_map <int,int> mp;
        for(int i = 0; i < n; i++){
            mp[in[i]] = i;
        }
        return solve(pre, in, mp, 0, n - 1, ind);
    }
};