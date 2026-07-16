// https://leetcode.com/problems/minimum-falling-path-sum/

//=============================================================================
// Approach 1 : Recursion
// Time Complexity : O(3^N)
// Space Complexity: O(N)
//=============================================================================

// class Solution {
// public:

//     int helper(int i,int j,vector<vector<int>>& matrix){

//         int n = matrix.size();
//         int m = matrix[0].size();

//         if(j<0 || j>=m)
//             return INT_MAX;

//         if(i==0)
//             return matrix[0][j];

//         int up = matrix[i][j] + helper(i-1,j,matrix);
//         int leftUp = matrix[i][j] + helper(i-1,j-1,matrix);
//         int rightUp = matrix[i][j] + helper(i-1,j+1,matrix);

//         return min(up,min(leftUp,rightUp));
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {

//         int n = matrix.size();
//         int m = matrix[0].size();

//         int ans = INT_MAX;

//         for(int j=0;j<m;j++)
//             ans = min(ans,helper(n-1,j,matrix));

//         return ans;
//     }
// };



//=============================================================================
// Approach 2 : Memoization (Top-Down DP)
// Time Complexity : O(N*M)
// Space Complexity: O(N*M) + O(N)
//=============================================================================

// class Solution {
// public:

//     int helper(int i,int j,vector<vector<int>>& matrix,
//                vector<vector<int>>& dp){

//         int m = matrix[0].size();

//         if(j<0 || j>=m)
//             return INT_MAX;

//         if(i==0)
//             return matrix[0][j];

//         if(dp[i][j]!=-1)
//             return dp[i][j];

//         int up = matrix[i][j] + helper(i-1,j,matrix,dp);
//         int leftUp = matrix[i][j] + helper(i-1,j-1,matrix,dp);
//         int rightUp = matrix[i][j] + helper(i-1,j+1,matrix,dp);

//         return dp[i][j]=min(up,min(leftUp,rightUp));
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {

//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<vector<int>> dp(n,vector<int>(m,-1));

//         int ans = INT_MAX;

//         for(int j=0;j<m;j++)
//             ans=min(ans,helper(n-1,j,matrix,dp));

//         return ans;
//     }
// };



//=============================================================================
// Approach 3 : Tabulation (Bottom-Up DP)
// Time Complexity : O(N*M)
// Space Complexity: O(N*M)
//=============================================================================

// class Solution {
// public:

//     int minFallingPathSum(vector<vector<int>>& matrix) {

//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<vector<int>> dp(n,vector<int>(m,0));

//         for(int j=0;j<m;j++)
//             dp[0][j]=matrix[0][j];

//         for(int i=1;i<n;i++){

//             for(int j=0;j<m;j++){

//                 int up = matrix[i][j] + dp[i-1][j];

//                 int leftUp = INT_MAX;
//                 if(j>0)
//                     leftUp = matrix[i][j] + dp[i-1][j-1];

//                 int rightUp = INT_MAX;
//                 if(j<m-1)
//                     rightUp = matrix[i][j] + dp[i-1][j+1];

//                 dp[i][j]=min(up,min(leftUp,rightUp));
//             }
//         }

//         int ans = INT_MAX;

//         for(int j=0;j<m;j++)
//             ans=min(ans,dp[n-1][j]);

//         return ans;
//     }
// };



//=============================================================================
// Approach 4 : Space Optimization
// Time Complexity : O(N*M)
// Space Complexity: O(M)
//=============================================================================

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m);

        for(int j=0;j<m;j++)
            prev[j]=matrix[0][j];

        for(int i=1;i<n;i++){

            vector<int> curr(m);

            for(int j=0;j<m;j++){

                int up = matrix[i][j] + prev[j];

                int leftUp = INT_MAX;
                if(j>0)
                    leftUp = matrix[i][j] + prev[j-1];

                int rightUp = INT_MAX;
                if(j<m-1)
                    rightUp = matrix[i][j] + prev[j+1];

                curr[j]=min(up,min(leftUp,rightUp));
            }

            prev=curr;
        }

        int ans = INT_MAX;

        for(int j=0;j<m;j++)
            ans=min(ans,prev[j]);

        return ans;
    }
};
