//It is like a fibonachhi number problem need to think like a array indexes in it 
// 0 .......... n
// 1. Try to represent any problems in terms of index
// 2. Do all possible stuffs on that index, according to the problem statement
// 3. Sum of all stuffs ->count all the ways , min(of all stuffs) -> Find min


#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cout<<"Total number of stairs : ";
     cin>>n;
     if(n<=2){cout<< n <<endl;return 0;}

     int prev = 1;
     int prev2 = 2;
     for(int i=3;i<n+1;i++){
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
     }
     cout<< prev <<endl;

     return 0;
}
