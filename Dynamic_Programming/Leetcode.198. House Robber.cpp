//It is a memoization solution and we have a tabulation approach and space optimization too but the file only contains memoization code
class Solution {
public:
    int helper(int ind,vector<int>&arr,vector<int>&dp){
        if(ind==0)return arr[0];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int pick = arr[ind] + helper(ind-2,arr,dp);
        int Notpick =  helper(ind-1,arr,dp);
        return dp[ind] = max(pick,Notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(n-1,nums,dp);
    }
};
