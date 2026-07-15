//Here is all the three or four approaches of this leetcode problem with subheadings.

//Recursive Approach of a question
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// class Solution {
// public:
//     long long helper(int i,int j,vector<vector<int>>&arr){
//         if(i==0&&j==0){
//             return  arr[i][j];
//         }
//         if(i<0 || j<0){
//             return INT_MAX;
//         }
//         long long up = arr[i][j] + helper(i-1,j,arr);
//         long long left = arr[i][j] + helper(i,j-1,arr);
//         return min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         return helper(n-1,m-1,grid);
//     }
// };

//Memoization Approach

// class Solution {
// public:
//     long long helper(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
//         if(i==0&&j==0){
//             return  arr[i][j];
//         }
//         if(i<0 || j<0){
//             return INT_MAX;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         long long up = arr[i][j] + helper(i-1,j,arr,dp);
//         long long left = arr[i][j] + helper(i,j-1,arr,dp);
//         return dp[i][j] = min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return helper(n-1,m-1,grid,dp);
//     }
// };

//Tabulation Approach

// class Solution {
//  public:
     
//      int minPathSum(vector<vector<int>>& grid) {
//          int n = grid.size();
//          int m = grid[0].size();
//          vector<vector<int>>dp(n,vector<int>(m,0));
//          dp[0][0] = grid[0][0];
//          for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 int up = INT_MAX;
//                 int left = INT_MAX;
//                 if(i==0&&j==0)continue;
//                 if(i>0){
//                  up = grid[i][j] + dp[i-1][j];}
//                 if(j>0){
//                  left = grid[i][j] + dp[i][j-1];}
//                 dp[i][j] = min(up,left);

//             }
//          }

//          return dp[n-1][m-1];
//      }
//  };
