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
    // reverse function should return new head
    ListNode* reverse(ListNode *head){
        ListNode * prev = NULL;
        while(head != NULL){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev; // new head after reverse
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

       
        slow = reverse(slow);

        
        ListNode* temp = head;
        while(slow != NULL){
            if(temp->val != slow->val){
                return false;
            }
            temp = temp->next;
            slow = slow->next;
        }
        return true; 
    }
};
