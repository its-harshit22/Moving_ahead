//It is a tabulation approach you need to just change few parameters to make it memoization in this que it is possible to optimize space but it is not needed so there is no code of it

class Solution {
public:
    bool helper(int ind,long long tar,vector<int>&arr,vector<vector<int>>&dp){
        if(tar==0)return true;
        if(ind==0){
            if(arr[ind]==tar)return true;
            return false;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        bool not_take = helper(ind-1,tar,arr,dp);
        bool take = false;
        if(arr[ind]<=tar)take=helper(ind-1,tar-arr[ind],arr,dp);
        return dp[ind][tar] = take|not_take;
        
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        if(sum%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,0));
        for(int i=0;i<n;i++)dp[i][0] = true;
        if(arr[0]<=sum/2)
        dp[0][arr[0]]=true;
        for(int i =1;i<n;i++){
            for(int tar = 1;tar<=sum/2;tar++){
                bool not_take = dp[i-1][tar];
                bool take=false;
                if(arr[i]<=tar)
                 take = dp[i-1][tar-arr[i]];
                 dp[i][tar] = take||not_take;
            }
        }
        return dp[n-1][sum/2];
    }
};
