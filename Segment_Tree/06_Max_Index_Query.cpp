#include<bits/stdc++.h>
using namespace std;

void builtTree(int ind,int l,int r,vector<int>&arr,vector<int>&segmentTree){
    if(l==r){
        segmentTree[ind] = l;
        return;
    }

    int mid = (l+r)/2;

    builtTree(2*ind+1,l,mid,arr,segmentTree);
    builtTree(2*ind+2,mid+1,r,arr,segmentTree);

    int t1 = segmentTree[2*ind+1];
    int t2 = segmentTree[2*ind+2];

    if(arr[t1] >= arr[t2])
        segmentTree[ind] = t1;
    else
        segmentTree[ind] = t2;
}

int Range_Index(int start,int end,int i,int l,int r,
                vector<int>&arr,vector<int>&segmentTree){

    if(l>end || r<start){
        return -1;
    }

    if(l>=start && r<=end){
        return segmentTree[i];
    }

    int mid = (l+r)/2;

    int leftIndex = Range_Index(start,end,2*i+1,l,mid,arr,segmentTree);
    int rightIndex = Range_Index(start,end,2*i+2,mid+1,r,arr,segmentTree);

    if(leftIndex == -1)
        return rightIndex;

    if(rightIndex == -1)
        return leftIndex;

    if(arr[leftIndex] >= arr[rightIndex])
        return leftIndex;
    else
        return rightIndex;
}

int main(){
    vector<int>arr = {100,5,3,1,2,7};

    int n = arr.size();

    vector<int>segmentTree(4*n,0);

    builtTree(0,0,n-1,arr,segmentTree);

    cout << Range_Index(0,3,0,0,n-1,arr,segmentTree) << endl;

    return 0;
}
