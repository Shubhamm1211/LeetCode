/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair <TreeNode*,ll>> q;
        q.push({root,0});
        ll maxi = 0;
        while(!q.empty()){
            ll n = q.size();
            ll startind = q.front().second;
            ll endind = q.back().second;
            maxi = max(maxi, endind - startind + 1);
            for(ll i = 0; i < n; i++){
                TreeNode *node = q.front().first;
                ll ind = q.front().second;
                ind -= startind;
                q.pop();
                if(node -> left){
                    q.push({node -> left, 2LL * ind + 1LL});
                }
                if(node -> right){
                    q.push({node -> right, 2LL * ind + 2LL});
                }
            }
        }
        return maxi;
    }
};