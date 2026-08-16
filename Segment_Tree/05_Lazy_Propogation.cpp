#include<bits/stdc++.h>
using namespace std;

void builtTree(int idx,int l,int r,vector<int>&nums,vector<int>&segmentTree){
    if(l==r){
        segmentTree[idx] = nums[l];
        return;
    }
    int mid = l + (r-l)/2;
    builtTree(2*idx+1,l,mid,nums,segmentTree);
    builtTree(2*idx+2,mid+1,r,nums,segmentTree);
    segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
}

void updateRange(int start, int end, int i, int l, int r, int val, vector<int>&segmentTree, vector<int>&Lazy){
    if(Lazy[i]!=0){
        segmentTree[i] += (r-l+1) * Lazy[i];
        if(l!=r){
            Lazy[2*i+1] += Lazy[i];
            Lazy[2*i+2] += Lazy[i];
        }
        Lazy[i] = 0;
    }
    if(l>end || r<start || l>r){
        return;
    }
    if(l>=start && r<=end){
        segmentTree[i] += (r-l+1) * val;
        if(l!=r){
            Lazy[2*i+1] += val;
            Lazy[2*i+2] += val;
        }
        return;
    }
    int mid = l + (r-l)/2;
    updateRange(start,end,2*i+1,l,mid,val,segmentTree,Lazy);
    updateRange(start,end,2*i+2,mid+1,r,val,segmentTree,Lazy);
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}

int main(){
     vector<int>nums = {3,4,2,5,3,6,3,4};
     int n  = nums.size();
     vector<int>segmentTree(4*n,0);
     vector<int>Lazy(4*n,0);
     builtTree(0,0,n-1,nums,segmentTree);
     for(auto it : segmentTree){
        if(it==0)continue;
        cout<< it <<endl;
     }
     updateRange(0,4,0,0,n-1,2,segmentTree,Lazy);
     for(auto it : segmentTree){
        if(it==0)continue;
        cout<< it <<endl;
     }
     return 0;
}
