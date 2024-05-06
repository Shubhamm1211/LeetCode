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
    ListNode*rev(ListNode*head){
        ListNode*prev,*curr;
        prev=NULL;
        curr=head;
        while(curr){
            ListNode*front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;;
    }
public:
     ListNode* removeNodes(ListNode* head) {
        head = rev(head);
        int max = head->val;
        ListNode *p = head;
        while(p->next){
            if(p->val>p->next->val){
                p->next=p->next->next;
            }
            else p=p->next;
        }
        head = rev(head);
        return head;
    }
};