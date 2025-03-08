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
    void inorder(TreeNode *root, map <TreeNode*,TreeNode*> &mp){
        if(!root) return;
        if(root -> left){
            mp[root -> left] = root;
            inorder(root -> left,mp);
        }
        if(root -> right){
            mp[root -> right] = root;
            inorder(root -> right,mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector <int> ans;
        map <TreeNode*,TreeNode*> mp; // mp[node] = parent;
        queue <TreeNode*> q;
        q.push(target);
        int lvl = 0;
        inorder(root,mp);
        for(auto &x : mp){
            cout << x.first -> val << " " << x.second -> val << endl;
        }
        map <TreeNode*,bool> vis;
        vis[target] = true;
        while(!q.empty()){
            int n = q.size();
            if(lvl == k) break;
            for(int i = 0; i < n; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp -> left and !vis[temp -> left]){
                    q.push(temp -> left);
                    vis[temp -> left] = true;
                }
                if(temp -> right and !vis[temp -> right]){
                    q.push(temp -> right);
                    vis[temp -> right] = true;
                }
                if(mp.find(temp) != mp.end() and !vis[mp[temp]]){
                    q.push(mp[temp]);
                    vis[mp[temp]] = true;
                }
            }
            lvl++;
        }
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }   
};