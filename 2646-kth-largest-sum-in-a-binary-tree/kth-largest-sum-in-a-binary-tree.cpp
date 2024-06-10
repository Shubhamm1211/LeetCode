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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<long long int>sum;
        while(!q.empty()){
            long long int n=q.size();
            long long s=0;
            for(long long int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                s=s+node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            sum.push_back(s);
        }
        if(k>sum.size())return -1;
        sort(sum.begin(),sum.end(),greater<long long int>());
        return sum[k-1];
    }
};