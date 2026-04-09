//Check give string is palindrome or not.
#include<bits/stdc++.h>
using namespace std;
void palindrome(string s,int i){
    if(i>=s.size()/2){
        cout<< "True" <<endl;
        return;
    }
    if(s[i]!=s[s.size()-i-1]){
        cout<< "False" <<endl;
        return;
    }
    palindrome(s,i+1);
}

int main(){
     string s;
     cin>>s;
     palindrome(s,0);
     return 0;
}
