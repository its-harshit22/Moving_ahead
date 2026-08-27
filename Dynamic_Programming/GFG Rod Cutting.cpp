class Solution {
  public:
  
    int helper(int ind,int N,vector<int>&price,vector<vector<int>>&dp){
        if(ind==0){
            return N * price[0];
        }
        if(dp[ind][N]!=-1){
            return dp[ind][N];
        }
        int not_take = 0 + helper(ind-1,N,price,dp);
        int take = INT_MIN;
        if(ind+1<=N){
            take = price[ind] + helper(ind,N-(ind+1),price,dp);
        }
        return dp[ind][N] = max(take,not_take);
    }
  
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(n-1,n,price,dp);
        
    }
};
