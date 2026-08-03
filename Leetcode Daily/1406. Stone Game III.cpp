class Solution {
public:

    int helper(int ind, vector<int>& stoneValue, vector<int>& dp){

        int n = stoneValue.size();

        if(ind >= n)
            return 0;

        if(dp[ind] != INT_MIN)
            return dp[ind];

        int take = 0;
        int maxi = INT_MIN;

        for(int k = 0; k < 3 && ind + k < n; k++){

            take += stoneValue[ind + k];

            maxi = max(maxi, take - helper(ind + k + 1, stoneValue, dp));
        }

        return dp[ind] = maxi;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int diff = helper(0, stoneValue, dp);

        if(diff > 0)
            return "Alice";
        if(diff < 0)
            return "Bob";

        return "Tie";
    }
};
