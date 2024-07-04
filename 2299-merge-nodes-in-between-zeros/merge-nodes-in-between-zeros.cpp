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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*curr=head->next;
        ListNode*head2=new ListNode(0);
        ListNode*curr2=head2;
        int sum=0;
        while(curr){
            sum+=curr->val;
            if(curr->val==0){
                ListNode*temp=new ListNode(sum);
                head2->next=temp;
                head2=temp;
                sum=0;
            }
            curr=curr->next;
        }
        return curr2->next;
    }
};