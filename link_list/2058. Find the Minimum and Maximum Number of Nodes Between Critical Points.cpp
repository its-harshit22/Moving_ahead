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
        int min_distance = INT_MAX;
        int max_distance = INT_MIN;
        vector<int>ans = {-1,-1};
        int n = 0;
        ListNode * temp = head;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        if(n<=3)return ans;
        ListNode * prev = head;
        ListNode * cur = head->next;
        ListNode * post = head->next->next;
        int idx = 2;
        int critical_point = 0;
        vector<int>index;
        while(post!=NULL){
            if(cur->val > prev->val && cur->val > post->val){
                index.push_back(idx);
                idx++;
                critical_point++;
            }
            else if(cur->val < prev->val && cur->val < post->val){
                index.push_back(idx);
                idx++;
                critical_point++;
            }
            else{
                idx++;
            }
            cur = cur->next;
            prev = prev->next;
            post = post->next;

        }
        if(critical_point<2)return ans;
        for(int i=0;i<index.size()-1;i++){
            min_distance = min(min_distance,index[i+1]-index[i]);
            
        }
        max_distance = index.back() - index.front();
        ans[0] = min_distance;
        ans[1] = max_distance;
        return ans;

    }
};
