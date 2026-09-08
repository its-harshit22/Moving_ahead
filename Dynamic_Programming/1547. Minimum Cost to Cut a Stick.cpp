class Solution {
public:

    int helper(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = 1e9;
        for(int idx = i;idx<=j;idx++){
            int steps = arr[j+1] - arr[i-1] + helper(i,idx-1,arr,dp)+helper(idx+1,j,arr,dp);
            if(steps<mini)mini = steps;
        }
        return dp[i][j] = mini;

    }

    int minCost(int n, vector<int>& cuts) {
        int s = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(s+1,vector<int>(s+1,-1));
        return helper(1,s,cuts,dp);

    }
};
