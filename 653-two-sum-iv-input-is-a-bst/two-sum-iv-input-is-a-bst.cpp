class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        stack<TreeNode*> leftst, rightst;
        TreeNode *curr = root;

        while (curr) {
            leftst.push(curr);
            curr = curr->left;
        }
        curr = root;
        while (curr) {
            rightst.push(curr);
            curr = curr->right;
        }

        TreeNode *l = leftst.top(); 
        leftst.pop();
        TreeNode *r = rightst.top(); 
        rightst.pop();
        while (l != r) { 
            int sum = l->val + r->val;
            if (sum == k) return true;
            else if (sum < k) {  
                if (l->right) {
                    l = l->right;
                    while (l) {
                        leftst.push(l);
                        l = l->left;
                    }
                }
                if (!leftst.empty()) {
                    l = leftst.top();
                    leftst.pop();
                }
            } 
            else { 
                if (r->left) {
                    r = r->left;
                    while (r) {
                        rightst.push(r);
                        r = r->right;
                    }
                }
                if (!rightst.empty()) {
                    r = rightst.top();
                    rightst.pop();
                }
            }
        }
        return false;
    }
};
