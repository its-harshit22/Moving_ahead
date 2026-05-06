#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s = "AABABAA";
    int k = 2;
    int maxLen = 0;
    for(int i=0;i<s.size();i++)
    {   int length = 0;
        int count_B = 0;
        for(int j=i;j<s.size();j++){
            if(s[j]=='B'){
                count_B++;
            }
            if(count_B>k){
                break;
            }
            length++;
        }
        maxLen = max(maxLen,length);

    }
    cout<< maxLen <<endl;
     return 0;
}
