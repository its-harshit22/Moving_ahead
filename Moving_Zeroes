#include<iostream>
#include<vector>
using namespace std;
void move_Zero(vector<int>&arr){
    int n = arr.size();
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[count] = arr[i];
            count++;
        }
    }
    for(int i=count;i<n;i++){
        arr[i] = 0;
    }

}

int main(){
    vector<int>arr = {0,1,0,3,5};
    move_Zero(arr);
    for(auto val:arr){
        cout<< val <<endl;
    }
     return 0;
}
