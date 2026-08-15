#include<bits/stdc++.h>
using namespace std;
void bulitTree(int ind,int left,int right,vector<int>&arr,vector<int>&segmentTree){
    if(left==right){
        segmentTree[ind] = arr[left];
        return;
    }
    int mid = (left+right)/2;
    bulitTree((2*ind)+1,left,mid,arr,segmentTree);
    bulitTree((2*ind)+2,mid+1,right,arr,segmentTree);
    segmentTree[ind] = segmentTree[2*ind+1] + segmentTree[2*ind+2];

}
void updateTree(int idx,int val,int i,int l,int r,vector<int>&segmentTree){
    if(l==r){
        segmentTree[i] += val;
        return;
    }
    int mid = (l+r)/2;
    if(idx<=mid){
        updateTree(idx,val,2*i+1,l,mid,segmentTree);
    }
    else{
        updateTree(idx,val,2*i+2,mid+1,r,segmentTree);
    }
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}

int main(){
     vector<int>arr(4,0);
     arr[0] = 3;
     arr[1] = 2;
     arr[2] = 5;
     arr[3] = 6;
     vector<int>segmentTree(2*4,0);
     bulitTree(0,0,3,arr,segmentTree);
     for(int i=0;i<8;i++){
        cout<< segmentTree[i] <<endl;
     }
     updateTree(1,2,0,0,3,segmentTree);
     for(int i=0;i<8;i++){
        cout<< segmentTree[i] <<endl;
     }
     return 0;
}
