class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i + 1 == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i + 1; k < j; k++) {

            int coins = nums[i] * nums[k] * nums[j]
                      + solve(i, k, nums, dp)
                      + solve(k, j, nums, dp);

            ans = max(ans, coins);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return solve(0, n + 1, nums, dp);
    }
};
