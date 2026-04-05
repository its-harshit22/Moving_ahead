#include<iostream>
using namespace std;
bool isArmstrong(int n){
    int a = n;
    int loc;
    int digit = 0;
    while(n>0){
        loc = n%10;
        digit += (loc*loc*loc);
        n = n/10;
    }
    if(a==digit)return true;
    return false;
}
int main(){
     int n = 371;
     cout<<isArmstrong(n);
     return 0;
}
