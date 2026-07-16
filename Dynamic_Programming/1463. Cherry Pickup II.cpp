// https://leetcode.com/problems/cherry-pickup-ii/

//=============================================================================
// Approach 1 : Recursion
// Time Complexity : O(9^R)
// Space Complexity: O(R)
//=============================================================================

// class Solution {
// public:

//     int helper(int i,int j1,int j2,int c,int r,vector<vector<int>>& grid){

//         if(j1<0 || j1>=c || j2<0 || j2>=c)
//             return -1e8;

//         if(i==r-1){
//             if(j1==j2)
//                 return grid[i][j1];
//             return grid[i][j1]+grid[i][j2];
//         }

//         int maxi=-1e8;

//         for(int dj1=-1;dj1<=1;dj1++){
//             for(int dj2=-1;dj2<=1;dj2++){

//                 int value;

//                 if(j1==j2)
//                     value=grid[i][j1];
//                 else
//                     value=grid[i][j1]+grid[i][j2];

//                 value+=helper(i+1,j1+dj1,j2+dj2,c,r,grid);

//                 maxi=max(maxi,value);
//             }
//         }

//         return maxi;
//     }

//     int cherryPickup(vector<vector<int>>& grid) {

//         int r=grid.size();
//         int c=grid[0].size();

//         return helper(0,0,c-1,c,r,grid);
//     }
// };



//=============================================================================
// Approach 2 : Memoization (Top-Down DP)
// Time Complexity : O(R*C*C*9)
// Space Complexity: O(R*C*C) + O(R)
//=============================================================================

// class Solution {
// public:

//     int helper(int i,int j1,int j2,int c,int r,
//                vector<vector<int>>& grid,
//                vector<vector<vector<int>>>& dp){

//         if(j1<0 || j1>=c || j2<0 || j2>=c)
//             return -1e8;

//         if(i==r-1){
//             if(j1==j2)
//                 return grid[i][j1];
//             return grid[i][j1]+grid[i][j2];
//         }

//         if(dp[i][j1][j2]!=-1)
//             return dp[i][j1][j2];

//         int maxi=-1e8;

//         for(int dj1=-1;dj1<=1;dj1++){
//             for(int dj2=-1;dj2<=1;dj2++){

//                 int value;

//                 if(j1==j2)
//                     value=grid[i][j1];
//                 else
//                     value=grid[i][j1]+grid[i][j2];

//                 value+=helper(i+1,j1+dj1,j2+dj2,c,r,grid,dp);

//                 maxi=max(maxi,value);
//             }
//         }

//         return dp[i][j1][j2]=maxi;
//     }

//     int cherryPickup(vector<vector<int>>& grid) {

//         int r=grid.size();
//         int c=grid[0].size();

//         vector<vector<vector<int>>> dp(
//             r,
//             vector<vector<int>>(c,vector<int>(c,-1))
//         );

//         return helper(0,0,c-1,c,r,grid,dp);
//     }
// };



//=============================================================================
// Approach 3 : Tabulation (Bottom-Up DP)
// Time Complexity : O(R*C*C*9)
// Space Complexity: O(R*C*C)
//=============================================================================

// class Solution {
// public:

//     int cherryPickup(vector<vector<int>>& grid) {

//         int r=grid.size();
//         int c=grid[0].size();

//         vector<vector<vector<int>>> dp(
//             r,
//             vector<vector<int>>(c,vector<int>(c,0))
//         );

//         for(int j1=0;j1<c;j1++){
//             for(int j2=0;j2<c;j2++){

//                 if(j1==j2)
//                     dp[r-1][j1][j2]=grid[r-1][j1];
//                 else
//                     dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
//             }
//         }

//         for(int i=r-2;i>=0;i--){

//             for(int j1=0;j1<c;j1++){

//                 for(int j2=0;j2<c;j2++){

//                     int maxi=-1e8;

//                     for(int dj1=-1;dj1<=1;dj1++){

//                         for(int dj2=-1;dj2<=1;dj2++){

//                             int value;

//                             if(j1==j2)
//                                 value=grid[i][j1];
//                             else
//                                 value=grid[i][j1]+grid[i][j2];

//                             if(j1+dj1>=0 && j1+dj1<c &&
//                                j2+dj2>=0 && j2+dj2<c)
//                                 value+=dp[i+1][j1+dj1][j2+dj2];
//                             else
//                                 value+=-1e8;

//                             maxi=max(maxi,value);
//                         }
//                     }

//                     dp[i][j1][j2]=maxi;
//                 }
//             }
//         }

//         return dp[0][0][c-1];
//     }
// };



//=============================================================================
// Approach 4 : Space Optimization
// Time Complexity : O(R*C*C*9)
// Space Complexity: O(C*C)
//=============================================================================

class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {

        int r=grid.size();
        int c=grid[0].size();

        vector<vector<int>> front(c,vector<int>(c,0));

        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){

                if(j1==j2)
                    front[j1][j2]=grid[r-1][j1];
                else
                    front[j1][j2]=grid[r-1][j1]+grid[r-1][j2];
            }
        }

        for(int i=r-2;i>=0;i--){

            vector<vector<int>> curr(c,vector<int>(c,0));

            for(int j1=0;j1<c;j1++){

                for(int j2=0;j2<c;j2++){

                    int maxi=-1e8;

                    for(int dj1=-1;dj1<=1;dj1++){

                        for(int dj2=-1;dj2<=1;dj2++){

                            int value;

                            if(j1==j2)
                                value=grid[i][j1];
                            else
                                value=grid[i][j1]+grid[i][j2];

                            if(j1+dj1>=0 && j1+dj1<c &&
                               j2+dj2>=0 && j2+dj2<c)
                                value+=front[j1+dj1][j2+dj2];
                            else
                                value+=-1e8;

                            maxi=max(maxi,value);
                        }
                    }

                    curr[j1][j2]=maxi;
                }
            }

            front=curr;
        }

        return front[0][c-1];
    }
};
