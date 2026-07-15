//Recursion

// class Solution {
// public:
//     int helper(int i,int j,vector<vector<int>>& obstacle){
//         if(i==0 && j==0)return 1;
//         if(i<0 || j<0)return 0;
//         if(obstacle[i][j]==1)return 0;
//         int up = helper(i-1,j,obstacle);
//         int left = helper(i,j-1,obstacle);
//         return up+left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
//         int n = obstacle.size();
//         int m = obstacle[0].size();

//         return helper(n-1,m-1,obstacle);
//     }
// };

//Memoization

// class Solution {
// public:
//     int helper(int i,int j,vector<vector<int>>& obstacle,vector<vector<int>>& dp){
//         if(i==0 && j==0)return 1;
//         if(i<0 || j<0)return 0;
//         if(obstacle[i][j]==1)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int up = helper(i-1,j,obstacle,dp);
//         int left = helper(i,j-1,obstacle,dp);
//         return dp[i][j] = up+left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
//         int n = obstacle.size();
//         int m = obstacle[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
        
//         if(obstacle[0][0]==1){
//             return 0;
//         }
//         if(n==1 && m == 1 && obstacle[0][0]==0){
//             return 1;
//         }
//         return helper(n-1,m-1,obstacle,dp);
//     }
// };

//Tabulation 

// class Solution {
// public:
//     int helper(int i,int j,vector<vector<int>>& obstacle,vector<vector<int>>& dp){
//         if(i==0 && j==0)return 1;
//         if(i<0 || j<0)return 0;
//         if(obstacle[i][j]==1)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int up = helper(i-1,j,obstacle,dp);
//         int left = helper(i,j-1,obstacle,dp);
//         return dp[i][j] = up+left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
//         int n = obstacle.size();
//         int m = obstacle[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,0));
        
//         if(obstacle[0][0]==1){
//             return 0;
//         }
//         if(n==1 && m == 1 && obstacle[0][0]==0){
//             return 1;
//         }
//         dp[0][0] = 1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(i==0 && j==0)continue;
//                 if(obstacle[i][j]==1)continue;
//                 else{
//                     int up = 0;
//                     int left = 0;
//                     if(i>0)up = dp[i-1][j];
//                     if(j>0)left = dp[i][j-1];
//                     dp[i][j] = up+left;
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

//space optimization

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {

        int n = obstacle.size();
        int m = obstacle[0].size();

        vector<int> prev(m, 0);

        for(int i = 0; i < n; i++) {

            vector<int> curr(m, 0);

            for(int j = 0; j < m; j++) {

                if(obstacle[i][j] == 1) {
                    curr[j] = 0;
                }
                else if(i == 0 && j == 0) {
                    curr[j] = 1;
                }
                else {

                    int up = 0;
                    int left = 0;

                    if(i > 0)
                        up = prev[j];

                    if(j > 0)
                        left = curr[j - 1];

                    curr[j] = up + left;
                }
            }

            prev = curr;
        }

        return prev[m - 1];
    }
};
