//Recursive Solution of Frog jump at max k step from any index...
//Time complextity = O(k^n)
//Space Complexity = O(n)stack spcae

// #include<bits/stdc++.h>
// using namespace std;
// int frog(int index,vector<int>&arr,int k){
//     if(index == 0)return 0;
//     int minStep = INT_MAX;
//     for(int j=1;j<=k;j++){
//         if(index-j<0)break;
//         int jump = frog(index-j,arr,k) + abs(arr[index]-arr[index-j]);
//         minStep = min(minStep,jump);

//     }
//     return minStep;


// }
// int main(){
//      int n;
//      cout<<"Enter the size of an array : ";
//      cin>>n;
//      cout<<"Enter the "<<n<<" elements one by one "<<endl;
//      vector<int>arr(n,-1);
//      for(int i=0;i<n;i++){
//         int element;
//         cin>>element;
//         arr[i] = element;
//     }
//     int k;
//     cout<< "Enter the max step we take from any index : ";
//     cin>>k;
//    cout << frog(n-1, arr, k);;
//      return 0;
// }

//Memoization Approach of it
//Time complexity = O(N*k)
//Space complextity = O(N)+O(N)

// #include<bits/stdc++.h>
// using namespace std;

// int frog(int index, vector<int>& arr, int k, vector<int>& dp) {
//     if(index == 0)
//         return 0;

//     if(dp[index] != -1)
//         return dp[index];

//     int minStep = INT_MAX;

//     for(int j = 1; j <= k; j++) {
//         if(index - j < 0)
//             break;

//         int jump = frog(index - j, arr, k, dp)
//                    + abs(arr[index] - arr[index - j]);

//         minStep = min(minStep, jump);
//     }

//     return dp[index] = minStep;
// }

// int main() {
//     int n;
//     cout << "Enter the size of an array : ";
//     cin >> n;

//     cout << "Enter the " << n << " elements one by one\n";

//     vector<int> arr(n);
//     for(int i = 0; i < n; i++)
//         cin >> arr[i];

//     int k;
//     cout << "Enter the max step we take from any index : ";
//     cin >> k;

//     vector<int> dp(n, -1);

//     cout << frog(n - 1, arr, k, dp);

//     return 0;
// }

//Tabulation

// Time Complexity
// O(n × k)
// Space Complexity
// O(n)

// #include<bits/stdc++.h>
// using namespace std;

// int frog(int n, vector<int>& arr, int k) {

//     vector<int> dp(n, 0);

//     dp[0] = 0;

//     for(int i = 1; i < n; i++) {

//         int minStep = INT_MAX;

//         for(int j = 1; j <= k; j++) {

//             if(i - j >= 0) {

//                 int jump = dp[i - j] + abs(arr[i] - arr[i - j]);

//                 minStep = min(minStep, jump);
//             }
//         }

//         dp[i] = minStep;
//     }

//     return dp[n - 1];
// }

// int main() {

//     int n;
//     cout << "Enter the size of an array : ";
//     cin >> n;

//     cout << "Enter the " << n << " elements one by one" << endl;

//     vector<int> arr(n);

//     for(int i = 0; i < n; i++)
//         cin >> arr[i];

//     int k;
//     cout << "Enter the max step we take from any index : ";
//     cin >> k;

//     cout << frog(n, arr, k);

//     return 0;
// }
