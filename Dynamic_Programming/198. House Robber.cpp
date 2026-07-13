//It is a tabulation solution of it
class Solution {
public:
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,-1);
        dp[0] = arr[0];
        int take = 0;
        int notTake = 0;

        for(int i=1;i<n;i++){
            take = arr[i];if(i-2>-1)take += dp[i-2];
            notTake = dp[i-1];
            dp[i] = max(take,notTake);
        }
        return dp[n-1];
    }
};
