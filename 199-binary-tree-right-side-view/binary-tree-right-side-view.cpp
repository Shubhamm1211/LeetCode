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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        vector<vector<int>>lo;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                v.push_back(node->val);
                if(node->right){
                    q.push(node->right);
                }

            }
            lo.push_back(v);
        }
        for(int i=0;i<lo.size();i++){
            reverse(lo[i].begin(),lo[i].end());
        }
        
        for(int i=0;i<lo.size();i++){
            ans.push_back(lo[i][0]);
        }
        return ans;
    }
};