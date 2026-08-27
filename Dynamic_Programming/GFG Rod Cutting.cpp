// DP 24: Rod Cutting Problem
// Approaches: Memoization + Tabulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Memoization
    int helper(int ind, int N, vector<int>& price, vector<vector<int>>& dp) {
        if (ind == 0) {
            return N * price[0];
        }

        if (dp[ind][N] != -1) {
            return dp[ind][N];
        }

        int not_take = helper(ind - 1, N, price, dp);

        int take = INT_MIN;
        if (ind + 1 <= N) {
            take = price[ind] +
                   helper(ind, N - (ind + 1), price, dp);
        }

        return dp[ind][N] = max(take, not_take);
    }

    int cutRodMemoization(vector<int>& price) {
        int n = price.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(n - 1, n, price, dp);
    }


    // Tabulation
    int cutRodTabulation(vector<int>& price) {
        int n = price.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int N = 0; N <= n; N++) {
            dp[0][N] = N * price[0];
        }

        for (int i = 1; i < n; i++) {
            for (int N = 0; N <= n; N++) {

                int not_take = dp[i - 1][N];

                int take = INT_MIN;

                if (i + 1 <= N) {
                    take = price[i] +
                           dp[i][N - (i + 1)];
                }

                dp[i][N] = max(take, not_take);
            }
        }

        return dp[n - 1][n];
    }
};
