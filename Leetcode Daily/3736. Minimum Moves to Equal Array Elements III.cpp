class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sum = 0;
        for(auto val : nums)sum = sum + (maxi-val);
        return sum;
    }
};
