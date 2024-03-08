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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>minh;
        int k=lists.size();
        ListNode*head=new ListNode(-1);
        ListNode*temp=head;
        for(int i=0;i<k;i++){
            ListNode*temp2=lists[i];
            while(temp2!=NULL){
            minh.push(temp2->val);
            temp2=temp2->next;
            }
        }
        while(!minh.empty()){
            ListNode *i=new ListNode(minh.top());
            minh.pop();
            head->next=i;
            head=head->next;
        }
        return temp->next;
    }
};