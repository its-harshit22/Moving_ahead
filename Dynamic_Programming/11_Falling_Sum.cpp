// https://leetcode.com/problems/minimum-falling-path-sum/

//=============================================================================
// Approach 1 : Recursion
// Time Complexity : O(3^n)
// Space Complexity: O(n)
//=============================================================================

// #include<bits/stdc++.h>
// using namespace std;

// long long recursion(int i,int j,vector<vector<int>>& matrix){

//     int n = matrix.size();
//     int m = matrix[0].size();

//     if(i==0 && j>=0 && j<m)
//         return matrix[0][j];

//     if(i<0 || j<0 || i>=n || j>=m)
//         return INT_MAX;

//     long long up = matrix[i][j] + recursion(i-1,j,matrix);
//     long long left_up = matrix[i][j] + recursion(i-1,j-1,matrix);
//     long long right_up = matrix[i][j] + recursion(i-1,j+1,matrix);

//     return min(up,min(left_up,right_up));
// }

// int main(){

//     int n;
//     cout<<"Enter the number of rows : ";
//     cin>>n;

//     int m;
//     cout<<"Enter the number of columns : ";
//     cin>>m;

//     vector<vector<int>> matrix(n,vector<int>(m));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>matrix[i][j];
//         }
//     }

//     long long ans = INT_MAX;

//     for(int j=0;j<m;j++){
//         ans = min(ans,recursion(n-1,j,matrix));
//     }

//     cout<<ans<<endl;

//     return 0;
// }



//=============================================================================
// Approach 2 : Memoization (Top-Down DP)
// Time Complexity : O(n*m)
// Space Complexity: O(n*m) + O(n)
//=============================================================================

// #include<bits/stdc++.h>
// using namespace std;

// long long memoization(int i,int j,vector<vector<int>>& matrix,
//                       vector<vector<int>>& dp){

//     int n = matrix.size();
//     int m = matrix[0].size();

//     if(i==0 && j>=0 && j<m)
//         return matrix[0][j];

//     if(i<0 || j<0 || i>=n || j>=m)
//         return INT_MAX;

//     if(dp[i][j]!=INT_MAX)
//         return dp[i][j];

//     long long up = matrix[i][j] + memoization(i-1,j,matrix,dp);
//     long long left_up = matrix[i][j] + memoization(i-1,j-1,matrix,dp);
//     long long right_up = matrix[i][j] + memoization(i-1,j+1,matrix,dp);

//     return dp[i][j]=min(up,min(left_up,right_up));
// }

// int main(){

//     int n;
//     cout<<"Enter the number of rows : ";
//     cin>>n;

//     int m;
//     cout<<"Enter the number of columns : ";
//     cin>>m;

//     vector<vector<int>> matrix(n,vector<int>(m));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>matrix[i][j];
//         }
//     }

//     vector<vector<int>> dp(n,vector<int>(m,INT_MAX));

//     long long ans = INT_MAX;

//     for(int j=0;j<m;j++){
//         ans = min(ans,memoization(n-1,j,matrix,dp));
//     }

//     cout<<ans<<endl;

//     return 0;
// }



//=============================================================================
// Approach 3 : Tabulation (Bottom-Up DP)
// Time Complexity : O(n*m)
// Space Complexity: O(n*m)
//=============================================================================

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cout<<"Enter the number of rows : ";
//     cin>>n;

//     int m;
//     cout<<"Enter the number of columns : ";
//     cin>>m;

//     vector<vector<int>> matrix(n,vector<int>(m));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>matrix[i][j];
//         }
//     }

//     vector<vector<int>> dp(n,vector<int>(m,0));

//     for(int j=0;j<m;j++)
//         dp[0][j]=matrix[0][j];

//     for(int i=1;i<n;i++){

//         for(int j=0;j<m;j++){

//             int up = matrix[i][j] + dp[i-1][j];

//             int left_up = INT_MAX;
//             if(j>0)
//                 left_up = matrix[i][j] + dp[i-1][j-1];

//             int right_up = INT_MAX;
//             if(j<m-1)
//                 right_up = matrix[i][j] + dp[i-1][j+1];

//             dp[i][j]=min(up,min(left_up,right_up));
//         }
//     }

//     int ans = INT_MAX;

//     for(int j=0;j<m;j++)
//         ans=min(ans,dp[n-1][j]);

//     cout<<ans<<endl;

//     return 0;
// }



//=============================================================================
// Approach 4 : Space Optimization
// Time Complexity : O(n*m)
// Space Complexity: O(m)
//=============================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns : ";
    cin>>m;

    vector<vector<int>> matrix(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    vector<int> prev(m,0);

    for(int j=0;j<m;j++)
        prev[j]=matrix[0][j];

    for(int i=1;i<n;i++){

        vector<int> curr(m,0);

        for(int j=0;j<m;j++){

            int up = matrix[i][j] + prev[j];

            int left_up = INT_MAX;
            if(j>0)
                left_up = matrix[i][j] + prev[j-1];

            int right_up = INT_MAX;
            if(j<m-1)
                right_up = matrix[i][j] + prev[j+1];

            curr[j]=min(up,min(left_up,right_up));
        }

        prev=curr;
    }

    int ans = INT_MAX;

    for(int j=0;j<m;j++)
        ans=min(ans,prev[j]);

    cout<<ans<<endl;

    return 0;
}
