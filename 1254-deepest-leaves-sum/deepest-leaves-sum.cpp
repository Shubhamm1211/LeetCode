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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return 0;
        if(root->right==NULL && root->left==NULL)return root->val;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                v.push_back(node->val);
            }
            
            ans.push_back(v);
        }
        int n=ans.size()-1;
        int res=accumulate(ans[n].begin(),ans[n].end(),0);
        return res;
    }
};