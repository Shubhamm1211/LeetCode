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
    void inorder(TreeNode*root,vector<int>&arr){
        if(root==NULL)return;
        if(root->left)inorder(root->left,arr);
        arr.push_back(root->val);
        if(root->right)inorder(root->right,arr);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int maxi=INT_MIN;
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }
        vector<int>ans;
        for(auto x:mp){
            if(x.second==maxi){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};