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
    int pairSum(ListNode* head) {
        vector<int>list;
        ListNode* temp = head;
        while(temp!=NULL){
            list.push_back(temp->val);
            temp = temp->next;
        }
        int st = 0;
        int end = list.size()-1;
        int maxSum = 0;
        while(st<end){
            maxSum = max(maxSum,list[st]+list[end]);
            st++;
            end--;
        }
        return maxSum;
        
    }
};
