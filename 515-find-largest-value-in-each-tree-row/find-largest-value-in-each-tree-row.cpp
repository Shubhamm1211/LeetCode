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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int maxi = 0;
        vector <int> ans;
        while(!q.empty()){
            int s = q.size();
            vector <int> temp;
            for(int i = 0; i < s; i++){
                TreeNode *f = q.front();
                q.pop();
                temp.push_back(f -> val);
                if(f -> left) q.push(f -> left);
                if(f -> right) q.push(f -> right);
            }
            int tm = *max_element(begin(temp),end(temp));
            ans.push_back(tm);
        }
        return ans;
    }
};