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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector <vector<int>> ans;
        queue <TreeNode*> q;
        q.push(root);
        bool f = true;
        while(!q.empty()){
            int s = q.size();
            vector <int> v;
            for(int i = 0; i < s; i++){
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp -> val);
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
            if(f){
                ans.push_back(v);
                f = !f;
            }
            else{
                reverse(begin(v), end(v));
                ans.push_back(v);
                f = !f;
            }
        } 
        return ans;
    }
};