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
    int amountOfTime(TreeNode* root, int target) {
        map <TreeNode*, TreeNode*> mp;
        TreeNode *start;
        queue <TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp -> val == target){
                    start = temp;
                }
                if(temp -> left){
                    mp[temp -> left] = temp;
                    q.push(temp -> left);
                }
                if(temp -> right){
                    mp[temp -> right] = temp;
                    q.push(temp -> right);
                }
            }
        }
        queue <TreeNode*> q2;
        q2.push(start);
        map <TreeNode*, int> vis;
        vis[start] = 1;
        while(!q2.empty()){
            int s = q2.size();
            bool f = false;
            for(int i = 0; i < s; i++){
                TreeNode *temp = q2.front();
                q2.pop();
                if(temp -> left and !vis[temp -> left]){
                    f = true;
                    vis[temp -> left] = 1;
                    q2.push(temp -> left);
                }
                if(temp -> right and !vis[temp -> right]){
                    f = true;
                    vis[temp -> right] = 1;
                    q2.push(temp -> right);
                }
                if(mp[temp] and !vis[mp[temp]]){
                    f = true;
                    vis[mp[temp]] = 1;
                    q2.push(mp[temp]);
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};