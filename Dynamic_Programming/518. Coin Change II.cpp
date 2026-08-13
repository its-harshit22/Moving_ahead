class Solution {
public:

    int helper(int ind, int tar, vector<int>& coins, int n,
               vector<vector<int>>& dp) {

        if(tar == 0)
            return 1;

        if(tar < 0 || ind >= n)
            return 0;

        if(dp[ind][tar] != -1)
            return dp[ind][tar];

        int not_take = helper(ind + 1, tar, coins, n, dp);

        int take = helper(ind, tar - coins[ind], coins, n, dp);

        return dp[ind][tar] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return helper(0, amount, coins, n, dp);
    }
};
