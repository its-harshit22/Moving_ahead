///Code of Fibonachi using Dynamic programming Its the start of the play list striver.
//Memoization Approach
//Step 1 = make dp array initalize everyone to -1
//Step 2 = Check Base cases
//Step 3 = Store and Return 
//Thats how you convert any recursion solution to DP solution.


// #include<bits/stdc++.h>
// using namespace std;

// int fibonachi(int n,vector<int>&dp){
//     if(n==0||n==1)return n;
//     if(dp[n]!=-1)return dp[n];
//     return dp[n] = fibonachi(n-1,dp)+fibonachi(n-2,dp);
// }
// int main(){
//     //Take input from user what fibonachi number you want
//      cout<< "Enter the fibo number u want : ";
//      int n;
//      cin>>n;
//      vector<int>dp(n+1,-1);
//      cout<<fibonachi(n,dp);
//      return 0;
// }

//Time complexity = O(n)
//Space complexity = O(n) + O(n);

//Tabulation Approach
//In tabulation we use bottom up Approach 

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//      int n;
//      cin>>n;
//      vector<int>dp(n+1,-1);
//      dp[0] = 0;
//      dp[1] = 1;
//      for(int i=2;i<n+1;i++){
//         dp[i] = dp[i-1]+dp[i-2];
//      }
//      cout<<dp[n];
//      return 0;
// }

//Time complexity = O(N)
//Space Complexity = O(N) //Still room of improvement 

#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cout<< "Enter the element : ";
     cin>>n;
     int prev = 1;
     int prev2 = 0;
     for(int i=2;i<n+1;i++){
        int curi = prev+prev2;
        prev2 = prev;
        prev = curi;
     }
     cout<< prev <<endl;
     return 0;
}
