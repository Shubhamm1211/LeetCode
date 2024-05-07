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
    ListNode*reverse(ListNode*head){
        ListNode*prev,*curr;
        prev=NULL;
        curr=head;
        while(curr){
            ListNode*front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode*head2=reverse(head);
        ListNode*temp=head2;
        int carry=0;
        ListNode*prev=NULL;
        while(temp){
            int t=(temp->val)*2 + carry;
            temp->val=t%10;
            if(t>9){
                carry=1;
            }
            else carry=0;
            prev=temp;
            temp=temp->next;
        }
        if(carry==1){
            ListNode*c=new ListNode(1);
            prev->next=c;
        }
        ListNode*ans=reverse(head2);
        return ans;
    }
};