//First need to do recursion
// 1. Try to represent any problems in terms of index
// 2. Do all possible stuffs on that index, according to the problem statement
// 3. Sum of all stuffs ->count all the ways , min(of all stuffs) -> Find min

// Than we Think About a memoization to convert recursion into DP.

//Time complextiy of the below solution is O(2^N)

// #include<bits/stdc++.h>
// using namespace std;
// int Jump(int ind,vector<int>&arr){
//     if(ind==0)return 0;
//     int left =  Jump(ind-1,arr) + abs(arr[ind] - arr[ind-1]);
//     int right = INT_MAX;
//     if(ind>1){
//         right = Jump(ind-2,arr) + abs(arr[ind] - arr[ind-2]);
//     }
//     return min(left,right);
// }

// int main(){
//     int n;
//     cout<< "Enter the size of an Array : ";
//     cin>>n;

//      vector<int>arr(n+1,0);
//      for(int i=0;i<n;i++){
//         int element;
//         cin>>element;
//         arr[i] = element;
//      }
//      cout<<Jump(n-1,arr);
//      return 0;
// }

//Memoization --> How to do --> Look at the parameter changes.....Only Index in this particular Question.

// #include<bits/stdc++.h>
// using namespace std;
// int Jump(int ind,vector<int>&arr,vector<int>&dp){
//     if(ind==0)return 0;
//     if(dp[ind]!=-1)return dp[ind];
//     int left =  Jump(ind-1,arr,dp) + abs(arr[ind] - arr[ind-1]);
//     int right = INT_MAX;
//     if(ind>1){
//         right = Jump(ind-2,arr,dp) + abs(arr[ind] - arr[ind-2]);
//     }
//     return dp[ind]=min(left,right);
// }

// int main(){
//     int n;
//     cout<< "Enter the size of an Array : ";
//     cin>>n;

//      vector<int>arr(n+1,0);
//      for(int i=0;i<n;i++){
//         int element;
//         cin>>element;
//         arr[i] = element;
//      }
//      vector<int>dp(n+1,-1);
//      cout<<Jump(n-1,arr,dp);
//      return 0;
// }

//Time complexity is around -----> O(N)
//Space Complexity is O(N) + O(N)

//Now its time to do this we Tabulation to solve and reduce the extra O(N)stack space
//1.Intialize the dp as it is memoization.
//2 Than see the base case.
//Than observer the patter 

//Here its a sudo code 
//dp[n] = 0;mark everthing to 0;
//dp[0] = 0;see in the above base case.
//for(i=1-->n){
//  fs = dp[ind-1]+abs(arr[i-1]+arr[i]);
//if(i>ind)
//  ss = dp[ind-1]+abs(arr[i-1]+arr[i]);


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<< "Enter the size of an Array : ";
    cin>>n;

    vector<int>arr(n+1,0);
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr[i] = element;
    }
    vector<int>dp(n,0);
    dp[0]= 0;
    for(int i=1;i<n;i++)
    {
      int fs = dp[i-1] + abs(arr[i]-arr[i-1]);
      int ss = INT_MAX;
      if(i>1)
      {
      ss = dp[i-2] + abs(arr[i]-arr[i-2]);
      
    }dp[i] = min(fs,ss);
    }
      cout<< dp[n-1] <<endl;
      return 0;
}

