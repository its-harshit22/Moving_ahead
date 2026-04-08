#include<iostream>
#include<vector>
using namespace std;

void backtrack_call(int i, int n){
    if(i > n){
        return;
    }
    backtrack_call(i + 1, n);
    cout << i << endl;
}

void backtrack_op(int i, int n){
    if(i < 1){
        return;
    }
    backtrack_op(i - 1, n);
    cout << i << endl;
}

int main(){
    int n;
    cin >> n;

    backtrack_call(1, n);   // prints n to 1
    backtrack_op(n, n);  // prints 1 to n

    return 0;
}
