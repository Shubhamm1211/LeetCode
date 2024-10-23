class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> sum;
        while (!q.empty()) {
            int levelSum = 0;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                levelSum += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            sum.push_back(levelSum);
        }

        q.push(root);
        int ind = 1;
        root->val = 0;  
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                int ss =
                    (curr->left ? curr->left->val : 0) +
                    (curr->right ? curr->right->val : 0);

                if (curr->left) {
                    curr->left->val = sum[ind] - ss;
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val =
                        sum[ind] - ss;
                    q.push(curr->right);
                }
            }
            ++ind;
        }
        return root;
    }
};