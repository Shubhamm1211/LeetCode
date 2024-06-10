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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>mat;
        while(!q.empty()){
            int n=q.size();
            vector<int>lvl;
            for(int i=0;i<n;i++){
            TreeNode*node=q.front();
            q.pop();
            lvl.push_back(node->val);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            }
            mat.push_back(lvl);
        }
        vector<int>sum;
        for(int i=0;i<mat.size();i++){
            int s=accumulate(mat[i].begin(),mat[i].end(),0);
            sum.push_back(s);
        }
        int ans=INT_MIN,ind;
        for(int i=0;i<sum.size();i++){
            if(sum[i]>ans){
                ans=sum[i];
                ind=i;
            }
        }
        return ind+1;
    }
};