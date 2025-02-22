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
    TreeNode *solve(string s, int &i, int depth){
        int n = s.size();
        if(i >= s.size()){
            return NULL;
        }
        int j = i;
        while(j < s.size() and s[j] == '-'){
            j++;
        }
        int dash  = j - i;
        if(depth != dash){
            return NULL;
        }
        i += dash;
        int num = 0;
        while(i < n and isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            i++;
        }
        TreeNode *node = new TreeNode(num);
        node -> left = solve(s, i, depth + 1);
        node -> right = solve(s, i, depth + 1);
        return node;
    }
    TreeNode* recoverFromPreorder(string s) {
        int i = 0;
        TreeNode *root;
        return solve(s,i,0);
    }
};