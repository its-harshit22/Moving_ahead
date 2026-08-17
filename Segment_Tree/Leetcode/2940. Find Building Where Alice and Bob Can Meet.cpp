class Solution {
public:
    void builtTree(int ind, int l, int r, vector<int>& arr, vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[ind] = l;
            return;
        }

        int mid = (l + r) / 2;

        builtTree(2 * ind + 1, l, mid, arr, segmentTree);
        builtTree(2 * ind + 2, mid + 1, r, arr, segmentTree);

        int t1 = segmentTree[2 * ind + 1];
        int t2 = segmentTree[2 * ind + 2];

        if (arr[t1] >= arr[t2])
            segmentTree[ind] = t1;
        else
            segmentTree[ind] = t2;
    }

    int Range_Index(int start, int end, int i, int l, int r,
                    vector<int>& arr, vector<int>& segmentTree) {
        if (l > end || r < start)
            return -1;

        if (l >= start && r <= end)
            return segmentTree[i];

        int mid = (l + r) / 2;

        int leftIndex = Range_Index(start, end, 2 * i + 1, l, mid,
                                    arr, segmentTree);

        int rightIndex = Range_Index(start, end, 2 * i + 2, mid + 1, r,
                                     arr, segmentTree);

        if (leftIndex == -1)
            return rightIndex;

        if (rightIndex == -1)
            return leftIndex;

        if (arr[leftIndex] >= arr[rightIndex])
            return leftIndex;
        else
            return rightIndex;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,vector<vector<int>>& queries) {
        int n = heights.size();

        vector<int> segmentTree(4 * n);

        builtTree(0, 0, n - 1, heights, segmentTree);

        vector<int> ans;

        for (auto& q : queries) {
            int l = min(q[0], q[1]);
            int r = max(q[0], q[1]);

            if (l == r) {
                ans.push_back(r);
            }
            else if (heights[l] < heights[r]) {
                ans.push_back(r);
            }
            else {
                int low = r + 1;
                int high = n - 1;
                int res = -1;

                while (low <= high) {
                    int mid = (low + high) / 2;

                    int index = Range_Index(
                        r + 1, mid, 0, 0, n - 1,
                        heights, segmentTree
                    );

                    if (index != -1 && heights[index] > heights[l]) {
                        res = index;
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }

                ans.push_back(res);
            }
        }

        return ans;
    }
};
