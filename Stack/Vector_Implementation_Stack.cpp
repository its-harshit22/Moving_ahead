#include<iostream>
#include<vector>
using namespace std;
class Stack{
    vector<int> v;
    int top = -1;
    public:
    void push(int val){
        v.push_back(val);
        top++;
    }
    int pop(){
        if(top==-1){
            cout<< "Empty Stack" <<endl;
            return -1;
        }
        int val = v[top];
        top--;
        v.pop_back();
        return val;
    }
    int top_fun(){

        return v[top];
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
     return 0;
}
