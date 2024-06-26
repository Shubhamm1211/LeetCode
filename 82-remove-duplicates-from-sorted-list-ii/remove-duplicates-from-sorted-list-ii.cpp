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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = new ListNode(0);
        temp->next = curr;
        ListNode* prev = temp;
        while (curr != NULL && curr->next != NULL) {
            if(curr->next && curr->val==curr->next->val){
                while(curr->next && curr->val==curr->next->val){
                    curr=curr->next;
                }
                prev->next=curr->next;
            }
            else{
                prev=prev->next;
            }
            curr=curr->next;
        }
        return temp->next;
    }
};

