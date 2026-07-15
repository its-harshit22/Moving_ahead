class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& obstacle,vector<vector<int>>& dp){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(obstacle[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up = helper(i-1,j,obstacle,dp);
        int left = helper(i,j-1,obstacle,dp);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int n = obstacle.size();
        int m = obstacle[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        if(obstacle[0][0]==1){
            return 0;
        }
        if(n==1 && m == 1 && obstacle[0][0]==0){
            return 1;
        }
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                if(obstacle[i][j]==1)continue;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0)up = dp[i-1][j];
                    if(j>0)left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
