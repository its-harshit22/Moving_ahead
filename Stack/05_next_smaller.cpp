#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int>a = {3,1,0,8,6};
    stack<int>s;
    vector<int>ans(5,0);
    for(int i=0;i<a.size();i++){
        if(s.size()>0 && s.top()>=a[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(a[i]);
    }
    for(int val:ans){
        cout<< val <<" ";
    }
     return 0;
}
