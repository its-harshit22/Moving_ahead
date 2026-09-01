#include<bits/stdc++.h>
using namespace std;


int main(){
     string s1;
     string s2;
     cout<< "Enter the String 1" <<endl;
     cin>>s1;
     cout<< "Enter the String 2" <<endl;
     cin>>s2;
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    for(int i=0;i<=n1;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=n2;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j] =  1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
    }
    int len = dp[n1][n2];
    string ans = "";
    for(int i=0;i<len;i++){
        ans += "&";
    }
    int i = n1;
    int j = n2;
    
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans[len-1] = s1[i-1];
            i--;
            j--;
            len--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<< ans <<endl;
    
}
