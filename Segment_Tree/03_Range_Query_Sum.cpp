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
int QuerySum(int start,int end,int i,int l,int r,vector<int>&segmentTree){
    if(l>end || r<start){
        return 0;
    }
    if(l>=start && r<=end){
        return segmentTree[i];
    }
    int mid = (l+r)/2;
    return QuerySum(start,end,2*i+1,l,mid,segmentTree) + QuerySum(start,end,2*i+2,mid+1,r,segmentTree);
}

int main(){
     vector<int>arr(6,0);
     arr[0] = 3;
     arr[1] = 2;
     arr[2] = 5;
     arr[3] = 6;
     arr[4] = 7;
     arr[5] = 9;
     vector<int>segmentTree(2*6,0);
     bulitTree(0,0,5,arr,segmentTree);
     for(int i=0;i<12;i++){
        cout<< segmentTree[i] <<endl;
     }
     cout<<QuerySum(1,3,0,0,5,segmentTree);
     return 0;
}
