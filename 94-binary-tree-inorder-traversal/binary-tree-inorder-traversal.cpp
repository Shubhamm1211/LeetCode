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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack <TreeNode*> st;
        st.push(NULL);
        vector <int> ans;
        TreeNode *temp = root;
        while(!st.empty()){
            if(temp){
                st.push(temp);
                temp = temp -> left;
            }
            else{
                if(st.size() == 1) break;
                temp = st.top();
                st.pop();
                if(temp){
                    ans.push_back(temp -> val);
                    temp = temp -> right;
                }
            }
        }
        return ans;
    }
};