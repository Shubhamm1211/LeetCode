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
    map <int,int> mp;
    TreeNode *construct(vector <int> &in, vector <int> &pre, int start, int end, int &ind){
        if(start > end) return NULL;
        TreeNode *root = new TreeNode(pre[ind]);
        int temp = mp[pre[ind]];
        ind++;
        root -> left = construct(in,pre,start, temp - 1, ind);
        root -> right = construct(in,pre,temp + 1, end, ind);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector <int> in(begin(preorder), end(preorder));
        sort(begin(in), end(in));
        int n = in.size();
        for(int i = 0; i < n; i++){
            mp[in[i]] = i;
        }
        int ind = 0;
        TreeNode *root = construct(in,preorder,0, n - 1, ind);
        return root;
    }
};