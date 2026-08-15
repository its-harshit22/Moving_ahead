class Solution {
  public:
    void builtTree(int ind,int l,int r,vector<int>&arr,vector<int>&segmentTree){
        if(l==r){
            segmentTree[ind] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        builtTree(2*ind+1,l,mid,arr,segmentTree);
        builtTree(2*ind+2,mid+1,r,arr,segmentTree);
        segmentTree[ind] = min(segmentTree[2*ind+1] , segmentTree[2*ind+2]);

    }
    int Range_Minimum(int start,int end,int i,int l,int r,vector<int>&segmentTree){
        if(l>end || r<start){
            return 1e9;
        }
        if(l>=start && r<=end){
            return segmentTree[i];
        }
        int mid = (l+r)/2;
        return min(Range_Minimum(start,end,2*i+1,l,mid,segmentTree) , Range_Minimum(start,end,2*i+2,mid+1,r,segmentTree));
    }
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>segmentTree(4*n,1e9);
        builtTree(0,0,n-1,arr,segmentTree);
        vector<int>ans;
        for(auto it : queries){
            int element = Range_Minimum(it[0],it[1],0,0,n-1,segmentTree);
            ans.push_back(element);
        }
        return ans;
        
    }
};
