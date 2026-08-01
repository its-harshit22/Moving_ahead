class Solution {
public:

    int helper(int i, int j, vector<int>& nums){

        if(i == j)
            return nums[i];

        int takeLeft = nums[i] - helper(i + 1, j, nums);

        int takeRight = nums[j] - helper(i, j - 1, nums);

        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        return helper(0, n - 1, nums) >= 0;
    }
};
