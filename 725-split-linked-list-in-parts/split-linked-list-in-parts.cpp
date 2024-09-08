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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len<=k){
            vector<ListNode*>ans;
            ListNode*t=head;
            while(t){
                ListNode*nex=t->next;
                t->next=NULL;
                ans.push_back(t);
                t=nex;
            }
            int numnull=k-len;
            for(int i=0;i<numnull;i++){
                ans.push_back(NULL);
            }
            return ans;
        }
        else{
            int each = len / k;         
            int firstextra = len % k;   
            vector<ListNode*>ans;
            ListNode* t = head;
            for (int i=0;i<k;i++) {
                ans.push_back(t); 
                int curr; 
                if(i<firstextra){
                    curr=each+1;
                }
                else curr=each;
                for (int j=1;j<curr;j++) {
                    t=t->next;  
                }
                ListNode*nex=t->next;
                t->next=NULL;  
                t=nex; 
            }
            return ans;
        }   
        }
    
};