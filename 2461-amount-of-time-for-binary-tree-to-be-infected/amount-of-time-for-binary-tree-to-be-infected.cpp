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
    int solve(TreeNode*root, TreeNode*tar,map<TreeNode*,TreeNode*>&mp){
        map<TreeNode*,int>vis;
        vis[tar]=1;
        queue<TreeNode*>q;
        q.push(tar);
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            bool f=false;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                if(node->left and !vis[node->left]){
                    f=true;
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right and !vis[node->right]){
                    f=true;
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mp[node] and !vis[mp[node]]){
                    f=true;
                    vis[mp[node]]=1;
                    q.push(mp[node]);
                }
            }
            if(f)ans++;
        }
        return ans;
    }
    TreeNode*findparent(TreeNode*root,int start,map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*ans;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->val==start)ans=node;
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        TreeNode*res=findparent(root,start,mp);
        int ans=solve(root,res,mp);
        return ans;
    }
};