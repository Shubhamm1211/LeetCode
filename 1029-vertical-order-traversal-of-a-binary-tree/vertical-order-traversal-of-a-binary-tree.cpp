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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int,vector <int>> mp;
        queue <pair<int,TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            int n = q.size();
            map <int, vector <int>> mp2;
            for(int i = 0; i < n; i++){
                int ind = q.front().first;
                TreeNode *temp = q.front().second;
                q.pop();
                mp2[ind].push_back(temp -> val);
                if(temp -> left){
                    q.push({ind - 1, temp -> left});
                }
                if(temp -> right){
                    q.push({ind + 1, temp -> right});
                }
            }
            for(auto x : mp2){
                sort(x.second.begin(), x.second.end());
                vector <int> v = mp[x.first];
                for(int i = 0; i < x.second.size(); i++){
                    v.push_back(x.second[i]);
                }
                mp[x.first] = v;
            }
        }
        vector <vector <int>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
