#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void TOH(int n,int l,int m,int r){
    if(n!=0){
        TOH(n-1,l,r,m);
        cout<< "move "<<l<<" to "<<r<<endl;
        TOH(n-1,m,l,r);
    }
    
}

int main(){
    TOH(3,1,2,3);
    return 0;
}
