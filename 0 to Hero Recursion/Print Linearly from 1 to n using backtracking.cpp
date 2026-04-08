#include<iostream>
#include<vector>
using namespace std;
void backtrack_call(int i,int n){
    if(i<1){
        return;
    }
    backtrack_call(i-1,n);
    cout<< i <<endl;
}

int main(){
    int n;
    cin>>n;
    backtrack_call(n,n);
     return 0;
}
