class Solution {
  public:
    int helper(int ind,int W,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(ind==0){
            if(W>=wt[0]){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[ind][W]!=-1)return dp[ind][W];
        int not_take = 0 + helper(ind-1,W,val,wt,dp);
        int take = INT_MIN;
        if(W>=wt[ind]){
            take = val[ind] + helper(ind-1,W-wt[ind],val,wt,dp);
        }
        return dp[ind][W] = max(take,not_take);
    }
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        int maxi = 0;
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        maxi = helper(n-1,W,val,wt,dp);
        return maxi;
        
    }
};
