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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int ans=0,n;
        while(head){
            int n=head->val;
            while(head and st.count(head->val)){
                n=head->val;
                head=head->next;
            }
            if(st.count(n))ans++;
            if(head){
                head=head->next;
            }
        }
        return ans;
        
    }
};