#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Stack{
    list<int>l;
    public:
    void push(int val){
    l.push_front(val);  // front me add
    }
    void pop(){
        l.pop_front();
    }
    int top(){
        return l.front();
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<< s.top() <<endl;
    s.pop();
    cout<< s.top() <<endl;
    s.pop();
    cout<< s.top() <<endl;
    s.pop();
    cout<< s.top() <<endl;
    s.pop();
     return 0;
}
