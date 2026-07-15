// https://leetcode.com/problems/unique-paths/description/

//=============================================================================
// Approach 1 : Recursion
// Time Complexity : O(2^(m*n))
// Space Complexity: O((m-1) + (n-1))
//=============================================================================

// #include<bits/stdc++.h>
// using namespace std;

// int recursion(int i,int j){
//     if(i==0 && j==0){
//         return 1;
//     }
//     if(i<0 || j<0){
//         return 0;
//     }

//     int up = recursion(i-1,j);
//     int left = recursion(i,j-1);

//     return up+left;
// }

// int main(){
//     int m;
//     cout<<"Enter the number of row : ";
//     cin>>m;

//     int n;
//     cout<<"Enter the number of col : ";
//     cin>>n;

//     cout<<recursion(m-1,n-1)<<endl;
//     return 0;
// }



//=============================================================================
// Approach 2 : Memoization (Top-Down DP)
// Time Complexity : O(m*n)
// Space Complexity: O(m*n) + O((m-1)+(n-1))
//=============================================================================

// #include<bits/stdc++.h>
// using namespace std;

// int memoization(int i,int j,vector<vector<int>>& dp){

//     if(i==0 && j==0) return 1;

//     if(i<0 || j<0) return 0;

//     if(dp[i][j]!=-1) return dp[i][j];

//     int up = memoization(i-1,j,dp);
//     int left = memoization(i,j-1,dp);

//     return dp[i][j]=up+left;
// }

// int main(){

//     int m;
//     cout<<"Enter the number of row : ";
//     cin>>m;

//     int n;
//     cout<<"Enter the number of col : ";
//     cin>>n;

//     vector<vector<int>> dp(m,vector<int>(n,-1));

//     cout<<memoization(m-1,n-1,dp)<<endl;

//     return 0;
// }



//=============================================================================
// Approach 3 : Tabulation (Bottom-Up DP)
// Time Complexity : O(m*n)
// Space Complexity: O(m*n)
//=============================================================================

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int m;
//     cout<<"Enter the number of row : ";
//     cin>>m;

//     int n;
//     cout<<"Enter the number of col : ";
//     cin>>n;

//     vector<vector<int>> dp(m,vector<int>(n,0));

//     for(int i=0;i<m;i++){

//         for(int j=0;j<n;j++){

//             if(i==0 && j==0){
//                 dp[i][j]=1;
//             }
//             else{

//                 int up=0,left=0;

//                 if(i>0)
//                     up=dp[i-1][j];

//                 if(j>0)
//                     left=dp[i][j-1];

//                 dp[i][j]=up+left;
//             }
//         }
//     }

//     cout<<dp[m-1][n-1]<<endl;

//     return 0;
// }



//=============================================================================
// Approach 4 : Space Optimization
// Time Complexity : O(m*n)
// Space Complexity: O(n)
//=============================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){

    int m;
    cout<<"Enter the number of row : ";
    cin>>m;

    int n;
    cout<<"Enter the number of col : ";
    cin>>n;

    vector<int> prev(n,0);

    for(int i=0;i<m;i++){

        vector<int> curr(n,0);

        for(int j=0;j<n;j++){

            if(i==0 && j==0){
                curr[j]=1;
            }
            else{

                int up=0,left=0;

                if(i>0)
                    up=prev[j];

                if(j>0)
                    left=curr[j-1];

                curr[j]=up+left;
            }
        }

        prev=curr;
    }

    cout<<prev[n-1]<<endl;

    return 0;
}
