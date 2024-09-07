/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode*root,ListNode*head){
        if(!root)return false;
        if(head->next==NULL)return true;
        if(head->val!=root->val){
            return false;
        }
        bool left=false;
        bool right=false;
        if(root->left and head->next and root->left->val==head->next->val){
            left=check(root->left,head->next);
        }
        if(root->right and head->next and root->right->val==head->next->val){
            right=check(root->right,head->next);
        }
        return left or right;

    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)return false;
        if(root->val==head->val){
            if(check(root,head)){
                return true;
            }
        }
        bool ans=isSubPath(head,root->left) or isSubPath(head,root->right);
        return ans;
    }
};