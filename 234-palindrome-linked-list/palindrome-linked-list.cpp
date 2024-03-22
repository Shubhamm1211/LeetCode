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
    ListNode* getmiddle(ListNode*head){
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *forward=head;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)return true;
        ListNode*middle=getmiddle(head);
        ListNode *temp=middle;
        middle=reverse(temp);
        ListNode *head1=head;
        ListNode *head2=middle;
        while(head2!=NULL){
            if(head1->val!=head2->val)return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};