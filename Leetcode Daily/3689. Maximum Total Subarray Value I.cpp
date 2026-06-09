class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_element = INT_MIN;
        int min_element = INT_MAX;
        for(int i=0;i<nums.size();i++){
            max_element = max(max_element,nums[i]);
            min_element = min(min_element,nums[i]);
        }
        long long ans = 0;
        ans = (max_element-min_element);
        ans = ans * k;
        return ans;
    }
};
