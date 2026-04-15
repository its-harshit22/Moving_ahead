#include<iostream>
#include<queue>
using namespace std;
//Queue is FIFO Data Structure.
//All other function similar to Stack.
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    // while(!q.empty()){
    //     cout<< q.front() <<endl;
    //     q.pop();
    // }
    cout<< q.size() <<endl;
     return 0;
}
