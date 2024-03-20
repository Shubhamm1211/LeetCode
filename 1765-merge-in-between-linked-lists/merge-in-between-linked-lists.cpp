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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list2;
        ListNode* temp2=list1;
        ListNode* atemp;
        while(temp->next!=NULL)temp=temp->next;
        int i=0;
        while(temp2!=NULL){
            if(i==a-1)atemp=temp2;
            else if(i==b+1){
                    break;
            }
            i++;
            temp2=temp2->next;
        } 
        atemp->next=list2;
        temp->next=temp2;
        return list1;
    }
};