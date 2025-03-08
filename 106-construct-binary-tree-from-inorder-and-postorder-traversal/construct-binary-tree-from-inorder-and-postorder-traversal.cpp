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
    TreeNode* solve(vector <int> &in, vector <int> &post, map <int,int> &mp, int start,int end, int &ind){
        if(start > end){
            return NULL;
        }
        TreeNode *temp = new TreeNode(post[ind]);
        int tempind = mp[post[ind]];
        ind--;
        temp -> right = solve(in,post,mp,tempind + 1, end, ind);
        temp -> left = solve(in,post,mp,start, tempind - 1, ind);
        return temp;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map <int,int> mp;
        for(int i = 0; i < in.size(); i++){
            mp[in[i]] = i;
        }
        int ind = in.size() - 1;
        return solve(in,post,mp,0,in.size() - 1, ind);
    }
};