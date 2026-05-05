class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        k = k % n;
        if (k == 0) return head;

        for (int i = 0; i < k; i++) {
            ListNode *prev = head;
            ListNode *cur = head->next;
            while (cur->next != NULL) {
                cur = cur->next;
                prev = prev->next;
            }
            prev->next = NULL;
            cur->next = head;
            head = cur;
        }
        return head;
    }
};
