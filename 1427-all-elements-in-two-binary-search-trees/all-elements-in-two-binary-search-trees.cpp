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
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL)return ;
        if(root->left)inorder(root->left,v);
        v.push_back(root->val);
        if(root->right)inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        inorder(root1,v1);
        vector<int>v2;
        inorder(root2,v2);
        vector<int>ans;
        for(auto it:v1)ans.push_back(it);
        for(auto it:v2)ans.push_back(it);
        sort(ans.begin(),ans.end());
        return ans;
    }
};