#include<bits/stdc++.h>

using namespace std;
void reverse(vector<int>&arr,int l,int r){
    if(l>r){
        return;
    }
    swap(arr[l],arr[r]);
    reverse(arr,l+1,r-1);
}
void reverse_with_one_pointer(vector<int>&arr,int i){
    if(i>=arr.size()/2){
        return;
    }
    swap(arr[i],arr[arr.size()-i-1]);
    reverse_with_one_pointer(arr,i+1);
}


int main(){
     vector<int>arr = {1,2,3,4,5};
     reverse(arr,0,arr.size()-1);
     for(auto i:arr){
        cout<< i <<endl;
     }
     reverse_with_one_pointer(arr,0);
     for(auto i:arr){
        cout<< i <<endl;
     }
     return 0;
}
