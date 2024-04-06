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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return -1;
        if(root->right==NULL && root->left==NULL)return -1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                ans.push_back(node->val);
            }
        }
        int mini=*min_element(ans.begin(),ans.end());
        sort(ans.begin(),ans.end());
        for(auto x:ans)cout<<x<<" ";
        int res=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>mini){
            res=ans[i];
            break;
            }
        }
        return res;
    }
};