#include<iostream>
#include<queue>
using namespace std;
//The commented section is default priority queue which is print in decreacing order.
int main(){
    // priority_queue<int> q;
    // q.push(1);
    // q.push(20);
    // q.push(3);
    // q.push(30);
    // while(!q.empty()){
    //     cout<<q.top()<<" ";
    //     q.pop();
    // }
    priority_queue<int ,vector<int> , greater<int>> q;
      q.push(1);
    q.push(20);
    q.push(3);
    q.push(30);
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
     return 0;
}
