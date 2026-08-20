class Solution {
public:

    void builtTree(int ind,int l,int r,vector<int>&baskets,vector<int>&segmentTree){
    if(l==r){
        segmentTree[ind] = baskets[l];
        return;
    }
    int mid = (l+r)/2;
    builtTree(2*ind+1,l,mid,baskets,segmentTree);
    builtTree(2*ind+2,mid+1,r,baskets,segmentTree);
    segmentTree[ind] = max(segmentTree[2*ind+1] , segmentTree[2*ind+2]);

    }

    bool querySegmentTree(int i,int l,int r,int val,vector<int>&segmentTree){
        if(segmentTree[i]<val)return false;
        if(l==r){
            segmentTree[i] = -1;
            return true;
        }

        int mid = l+(r-l)/2;
        bool placed = false;
        if(segmentTree[2*i+1]>=val){
            placed = querySegmentTree(2*i+1,l,mid,val,segmentTree);
        }
        else{
            placed = querySegmentTree(2*i+2,mid+1,r,val,segmentTree);
        }
        segmentTree[i] = max(segmentTree[2*i+1],segmentTree[2*i+2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int>segmentTree(4*n,-1);
        builtTree(0,0,n-1,baskets,segmentTree);

        int unplaced = 0;

        for(int i=0;i<n;i++){
            if(querySegmentTree(0,0,n-1,fruits[i],segmentTree)==false){
                unplaced++;
            }
        }

        return unplaced;


    }
};
