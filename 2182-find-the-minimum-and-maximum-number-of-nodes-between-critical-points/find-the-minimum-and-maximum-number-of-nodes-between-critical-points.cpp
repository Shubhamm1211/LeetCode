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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev=head;
        ListNode*curr=head->next;
        ListNode*forw=head->next->next;
        vector<int>v;
        int i=1;
        while(forw){
            i++;
            if(prev->val>curr->val and curr->val < forw->val){
                v.push_back(i);
            }
            else if(prev->val < curr->val and curr->val > forw->val){
                v.push_back(i);
            }
            prev=curr;
            curr=forw;
            forw=forw->next;
            
        }
        int n=v.size();
        if(v.empty()||n<2)return {-1,-1};
        int maxi= v[n-1]-v[0];
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            
            mini=min(mini,abs(v[i]-v[i+1]));
            
        }
        for(auto x:v)cout<<x<<" ";
        return {mini,maxi};
        
        // return v;

    }
};