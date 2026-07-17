// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//=============================================================================
// Approach 1 : Recursion
// Time Complexity : O(2^N)
// Space Complexity: O(N)
//=============================================================================

// class Solution {
// public:

//     bool helper(int ind,int tar,vector<int>& arr){

//         if(tar==0)
//             return true;

//         if(ind==0)
//             return arr[0]==tar;

//         bool not_take=helper(ind-1,tar,arr);

//         bool take=false;
//         if(arr[ind]<=tar)
//             take=helper(ind-1,tar-arr[ind],arr);

//         return take||not_take;
//     }

//     bool isSubsetSum(vector<int>& arr,int sum){

//         int n=arr.size();

//         return helper(n-1,sum,arr);
//     }
// };



//=============================================================================
// Approach 2 : Memoization (Top-Down DP)
// Time Complexity : O(N*Sum)
// Space Complexity: O(N*Sum) + O(N)
//=============================================================================

// class Solution {
// public:

//     bool helper(int ind,int tar,vector<int>& arr,
//                 vector<vector<int>>& dp){

//         if(tar==0)
//             return true;

//         if(ind==0)
//             return arr[0]==tar;

//         if(dp[ind][tar]!=-1)
//             return dp[ind][tar];

//         bool not_take=helper(ind-1,tar,arr,dp);

//         bool take=false;
//         if(arr[ind]<=tar)
//             take=helper(ind-1,tar-arr[ind],arr,dp);

//         return dp[ind][tar]=take||not_take;
//     }

//     bool isSubsetSum(vector<int>& arr,int sum){

//         int n=arr.size();

//         vector<vector<int>> dp(n,vector<int>(sum+1,-1));

//         return helper(n-1,sum,arr,dp);
//     }
// };



//=============================================================================
// Approach 3 : Tabulation (Bottom-Up DP)
// Time Complexity : O(N*Sum)
// Space Complexity: O(N*Sum)
//=============================================================================

// class Solution {
// public:

//     bool isSubsetSum(vector<int>& arr,int sum){

//         int n=arr.size();

//         vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

//         for(int i=0;i<n;i++)
//             dp[i][0]=true;

//         if(arr[0]<=sum)
//             dp[0][arr[0]]=true;

//         for(int i=1;i<n;i++){

//             for(int target=1;target<=sum;target++){

//                 bool not_take=dp[i-1][target];

//                 bool take=false;

//                 if(arr[i]<=target)
//                     take=dp[i-1][target-arr[i]];

//                 dp[i][target]=take||not_take;
//             }
//         }

//         return dp[n-1][sum];
//     }
// };



//=============================================================================
// Approach 4 : Space Optimization
// Time Complexity : O(N*Sum)
// Space Complexity: O(Sum)
//=============================================================================

class Solution {
public:

    bool isSubsetSum(vector<int>& arr,int sum){

        int n=arr.size();

        vector<bool> prev(sum+1,false);

        prev[0]=true;

        if(arr[0]<=sum)
            prev[arr[0]]=true;

        for(int i=1;i<n;i++){

            vector<bool> curr(sum+1,false);

            curr[0]=true;

            for(int target=1;target<=sum;target++){

                bool not_take=prev[target];

                bool take=false;

                if(arr[i]<=target)
                    take=prev[target-arr[i]];

                curr[target]=take||not_take;
            }

            prev=curr;
        }

        return prev[sum];
    }
};
