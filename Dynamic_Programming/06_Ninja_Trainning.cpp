//Ninja Trainning Question on coding Ninja
//Recursive approach
//Time complexity == O(3ⁿ)
//Space complexity == O(n)

// #include<bits/stdc++.h>
// using namespace std;
// int ninja(int day,int last,vector<vector<int>>&points){
//     if(day==0){
//         int maxi = 0;
//         for(int i=0;i<=2;i++){
//             if(i!=last){
//                 maxi = max(maxi,points[0][i]);
//             }
//         }
//         return maxi;
//     }
//     int maxi = 0;
//     for(int task = 0;task<=2;task++){
//         if(task!=last){
//             int point = points[day][task] + ninja(day-1,task,points);
//             maxi = max(point,maxi);
//         }
//     }
//     return maxi;

// }

// int main(){
//      int n;
//      cout<< "Enter the number of row : ";
//      cin>>n;
//      vector<vector<int>>points(n,vector<int>(3,0));
//      for(int i=0;i<n;i++){
//         for(int j=0;j<3;j++){
//             int element;
//             cin>>element;
//             points[i][j] = element;
//         }
//      }
    
//      cout<<ninja(n-1,3,points);


//      return 0;
// }


//Memoization
//tc = O(n)
//sc = O(2n)

// #include<bits/stdc++.h>
// using namespace std;
// int ninja(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
//     if(day==0){
//         int maxi = 0;
//         for(int i=0;i<=2;i++){
//             if(i!=last){
//                 maxi = max(maxi,points[0][i]);
//             }
//         }
//         return maxi;
//     }
//     if(dp[day][last]!=-1)return dp[day][last];
//     int maxi = 0;
//     for(int task = 0;task<=2;task++){
//         if(task!=last){
            
//             int point = points[day][task] + ninja(day-1,task,points,dp);
//             maxi = max(point,maxi);
//         }
//     }
//     return dp[day][last]=maxi;

// }

// int main(){
//      int n;
//      cout<< "Enter the number of row : ";
//      cin>>n;
//      vector<vector<int>>points(n,vector<int>(3,0));
//      for(int i=0;i<n;i++){
//         for(int j=0;j<3;j++){
//             int element;
//             cin>>element;
//             points[i][j] = element;
//         }
//      }
//      vector<vector<int>>dp(n,vector<int>(4,-1));
    
//      cout<<ninja(n-1,3,points,dp);


//      return 0;
// }

 

//Tabulation 
//Reduce the stack space....

// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//      int n;
//      cout<< "Enter the number of row : ";
//      cin>>n;
//      vector<vector<int>>points(n,vector<int>(3,0));
//      for(int i=0;i<n;i++){
//         for(int j=0;j<3;j++){
//             int element;
//             cin>>element;
//             points[i][j] = element;
//         }
//      }
//      vector<vector<int>>dp(n,vector<int>(4,0));
    
//      dp[0][0] = max(points[0][1],points[0][2]);
//      dp[0][1] = max(points[0][0],points[0][2]);
//      dp[0][2] = max(points[0][1],points[0][0]);
//      dp[0][3] = max(points[0][1],max(points[0][2],points[0][0]));

//      for(int day=1;day<n;day++ )
//      {
//         for(int last =0;last<4;last++)
//         {
//             dp[day][last] = 0;
//             int maxi = INT_MIN;
//             for(int task = 0;task<=2;task++)
//             {
//                 if(task!=last){
            
//                 int point = points[day][task] + dp[day-1][task];
//                 maxi = max(point,maxi);
//                                 }
//             }
//             dp[day][last] = maxi;
//         }
//      }

//      cout<< dp[n-1][3] <<endl;
//      return 0;
// }

//Space optimization 
//Reduce the stack space....

#include<bits/stdc++.h>
using namespace std;


int main(){
     int n;
     cout<< "Enter the number of row : ";
     cin>>n;
     vector<vector<int>>points(n,vector<int>(3,0));
     for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int element;
            cin>>element;
            points[i][j] = element;
        }
     }
     vector<int>dp(4,0);
    
     dp[0]= max(points[0][1],points[0][2]);
     dp[1] = max(points[0][0],points[0][2]);
     dp[2] = max(points[0][1],points[0][0]);
     dp[3] = max(points[0][1],max(points[0][2],points[0][0]));

     for(int day=1;day<n;day++ )
     {
        vector<int>temp(4,0);
        for(int last =0;last<4;last++)
        {
            temp[last] = 0;
            
            for(int task = 0;task<=2;task++)
            {
                if(task!=last){
                    temp[last] = max(temp[last],points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
     }

     cout<< dp[3] <<endl;
     return 0;
}
