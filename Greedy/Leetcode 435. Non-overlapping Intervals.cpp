class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
       
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];});

        int count = 1;
        int freeTime = intervals[0][1];
        for(int i=1;i<n;i++){
            if(freeTime<=intervals[i][0]){
                count++;
                freeTime = intervals[i][1];
            }
        }
        return n-count;


    }
};
