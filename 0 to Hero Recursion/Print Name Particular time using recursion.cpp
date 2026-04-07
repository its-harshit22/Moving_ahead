//Print your name five times through recursion

#include<iostream>
#include<vector>
using namespace std;
void name(int count){
    if(count==5){
        return;
    }
    cout<< "Harshit" <<endl;
    count++;
    name(count);
}

int main(){
    name(0);
     return 0;
}
