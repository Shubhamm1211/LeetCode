class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        while (temp != nullptr) {
            int sum = 0;
            ListNode* current = temp->next;
            while (current != nullptr) {
                sum += current->val;
                if (sum == 0) {
                    temp->next = current->next;
                }
                current = current->next;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};
