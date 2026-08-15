class NumArray {
public:

    vector<int> segmentTree;
    int n;

    void buildTree(int ind, int left, int right, vector<int>& nums) {

        if(left == right) {
            segmentTree[ind] = nums[left];
            return;
        }

        int mid = (left + right) / 2;

        buildTree(2 * ind + 1, left, mid, nums);
        buildTree(2 * ind + 2, mid + 1, right, nums);

        segmentTree[ind] =
            segmentTree[2 * ind + 1] +
            segmentTree[2 * ind + 2];
    }

    void updateTree(int ind, int left, int right,
                    int pos, int val) {

        if(left == right) {
            segmentTree[ind] = val;
            return;
        }

        int mid = (left + right) / 2;

        if(pos <= mid) {
            updateTree(2 * ind + 1, left, mid, pos, val);
        }
        else {
            updateTree(2 * ind + 2, mid + 1, right, pos, val);
        }

        segmentTree[ind] =
            segmentTree[2 * ind + 1] +
            segmentTree[2 * ind + 2];
    }

    int querySum(int start, int end, int ind,
                 int left, int right) {

        
        if(right < start || left > end) {
            return 0;
        }

        
        if(left >= start && right <= end) {
            return segmentTree[ind];
        }

        int mid = (left + right) / 2;

        return querySum(start, end, 2 * ind + 1,
                        left, mid)
             +
               querySum(start, end, 2 * ind + 2,
                        mid + 1, right);
    }

    NumArray(vector<int>& nums) {

        n = nums.size();

        segmentTree.resize(4 * n);

        buildTree(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {

        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {

        return querySum(left, right, 0, 0, n - 1);
    }
};
