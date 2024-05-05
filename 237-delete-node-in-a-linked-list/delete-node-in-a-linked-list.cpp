/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* Node) {
        ListNode*curr=Node->next;
        Node->val=curr->val;
        Node->next=curr->next;
    }
};