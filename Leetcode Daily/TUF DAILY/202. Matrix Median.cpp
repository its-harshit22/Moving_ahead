class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(matrix[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        n = temp.size();
        return temp[n/2];
    }
};
