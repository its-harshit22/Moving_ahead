class Solution {
public:

   

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i];

        if(sum < abs(target))
            return 0;

        if((sum + target) % 2 != 0)
            return 0;

        int tar = (sum + target) / 2;
        vector<vector<int>>dp(n,vector<int>(tar+1,0));
        for(int i=0;i<n;i++){
            if(nums[0] == 0)
                dp[0][0] = 2;
            else
                dp[0][0] = 1;

            if(nums[0] != 0 && nums[0] <= tar)
                dp[0][nums[0]] = 1;
            
        }
        for(int i=1;i<n;i++){
            for(int target = 0;target<=tar;target++){
                int not_take = dp[i-1][ target];

                int take = 0;
            if(nums[i] <= target)
                take = dp[i-1][ target-nums[i]];
                dp[i][target] = take + not_take;
            }
        }

        return dp[n-1][ tar];
    }
};
