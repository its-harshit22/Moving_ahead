class Solution {
public:

    int helper(int ind, vector<int>& dp, vector<int>& nums){

    int n = nums.size();

    if(ind >= n-1)
        return 0;

    if(dp[ind] != -1)
        return dp[ind];

    int mini = INT_MAX;

    for(int jump = 1; jump <= nums[ind]; jump++){

        if(ind + jump < n){

            int temp = helper(ind + jump, dp, nums);

            if(temp != INT_MAX)
                mini = min(mini, temp + 1);
        }
    }

    return dp[ind] = mini;
}

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(0,dp,nums);
    }
};
