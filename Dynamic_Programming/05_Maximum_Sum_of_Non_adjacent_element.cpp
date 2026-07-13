//Recursion 
//Time complexity = O(2^n)
//Space Complexity = O(n)stack space
// #include<bits/stdc++.h>
// using namespace std;

// int adjSum(int ind, vector<int>& arr) {
//     if(ind == 0)
//         return arr[0];

//     if(ind < 0)
//         return 0;

//     int pick = arr[ind] + adjSum(ind-2, arr);
//     int notPick = adjSum(ind-1, arr);

//     return max(pick, notPick);
// }

// int main() {
//     int n;
//     cout << "Enter the size of an array : ";
//     cin >> n;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
     

//     cout << adjSum(n-1, arr);

//     return 0;
// }

// //Memoization Approach
// //Time complexity = O(N)
// //Space complexity = O(N)+O(N)stack space and dp array
// #include<bits/stdc++.h>
// using namespace std;

// int adjSum(int ind, vector<int>& arr,vector<int>&dp) {
//      if(ind == 0)
//         return arr[0];

//      if(ind < 0)
//         return 0;
//      if(dp[ind]!=-1)return dp[ind];

//      int pick = arr[ind] + adjSum(ind-2, arr,dp);
     
//      int notPick = adjSum(ind-1, arr,dp);

//      return dp[ind] = max(pick, notPick);
// }

// int main() {
//     int n;
//     cout << "Enter the size of an array : ";
//     cin >> n;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];
     
//      vector<int>dp(n,-1);
//     cout << adjSum(n-1, arr,dp);

//     return 0;
// }


//Tabulation 
//Time complexity = O(N)
//Space complexoty = O(N)dp array

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
     
     vector<int>dp(n,-1);
    dp[0] = arr[0];
    int neg = 0;
    int take = 0;
    int nottake = 0;
    for(int i=1;i<n;i++){
        
         take = arr[i];if(i-2>-1)take += dp[i-2];
         nottake = dp[i-1];
        dp[i] = max(take,nottake);
    }
    cout<< dp[n-1] <<endl;

    return 0;
}
