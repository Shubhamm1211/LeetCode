/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildmap(TreeNode*root,map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        buildmap(root,mp);
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,int>vis;
        vis[target]=1;
        while(!q.empty()){
            int s=q.size();
            if(k==0)break;
            k--;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                if(!vis[node->left] and node->left){
                    q.push(node->left);
                    vis[node->left]=1;
                    
                }
                if(!vis[node->right] and node->right){
                    q.push(node->right);
                    vis[node->right]=1;
                    
                }
                if(!vis[mp[node]] and mp[node]){
                    q.push(mp[node]);
                    vis[mp[node]]=1;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            auto node=q.front();
            ans.push_back(node->val);
            q.pop();
        }
        return ans;
    }
};