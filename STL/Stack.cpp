#include<iostream>
#include<stack>
using namespace std;
//Stack is a FILO data structure.
int main(){
     stack<int> s;
     s.push(1);//To push element into stack
     s.push(2);
     s.push(3);
    //  while(!s.empty())//Empty check karne ke liye
    //  {
    //  cout<< s.top()<<endl;//Print karne ke liye top()
    // s.pop();//To pop element from top
    //  }
     cout<<s.size()<<endl;//size print karne ke liye
     stack<int> s2;
     s2.swap(s);
     cout<< s2.size() <<endl;
     cout<< s.size() <<endl;
     return 0;
}
