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

    void solve(TreeNode* root,string s,vector<string>&v){
        if(root==NULL){
            if(s!="")
            return;
            else
            v.push_back(s);
            // return;
        }
        s=s+to_string(root->val)+"->";
        if(!root->left and !root->right){
            s=s.substr(0,s.size()-2);
            v.push_back(s);
        }
        if(root->left)
        solve(root->left,s,v);
        if(root->right)
        solve(root->right,s,v);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string>v;
        solve(root,s,v);
        return v;
        
    }
};
