class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ele;
        int n = nums.size();
        ele = nums[n/2];
        int ans = 0;
        for(auto num : nums){
            ans = ans + abs(num-ele);
        }
        return ans;
    }
};
