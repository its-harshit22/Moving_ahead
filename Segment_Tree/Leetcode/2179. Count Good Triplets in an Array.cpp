class Solution {
public:

    void updateSegmentTree(int i,int l,int r,int idx,vector<long long>&segmentTree){
        if(l==r){
            segmentTree[i] = 1;
            return ;
        }

        int mid = l+(r-l)/2;
        if(idx<=mid){
            updateSegmentTree(2*i+1,l,mid,idx,segmentTree);
        }
        else{
            updateSegmentTree(2*i+2,mid+1,r,idx,segmentTree);
        }
        
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
        return;
    }

    long long querySegmentTree(int start,int end,int i,int l,int r,vector<long long>&segmentTree){
        if(l>end || r<start){
            return 0;
        }

        if(l>=start && r<=end){
            return segmentTree[i];
        }

        int mid = l+(r-l)/2;

        long long left = querySegmentTree(start,end,2*i+1,l,mid,segmentTree);
        long long right = querySegmentTree(start,end,2*i+2,mid+1,r,segmentTree);

        return left+right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n = nums1.size();
        
        for(int i=0;i<n;i++){
            mp[nums2[i]] = i;
        }

        vector<long long>segmentTree(4*n,0);
        long long result = 0;

        updateSegmentTree(0, 0, n-1, mp[nums1[0]], segmentTree);

        for(int i = 1; i < n; i++){
            int idx = mp[nums1[i]];

            long long leftCommonCount = querySegmentTree(0,idx,0,0,n-1,segmentTree);
            long long leftUncommonCount = i - leftCommonCount;

            long long elementsAfterIdxNums2 = (n-1) - idx;
            long long rightCommonCount = elementsAfterIdxNums2 - leftUncommonCount;

            result += leftCommonCount * rightCommonCount;
            updateSegmentTree(0, 0, n-1, idx, segmentTree);  
        }

        return result;
    }
};
