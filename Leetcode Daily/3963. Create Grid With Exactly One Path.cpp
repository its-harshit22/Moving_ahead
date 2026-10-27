class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string rowTop(n,'.');
        string remain(n-1,'#');
        remain = remain + '.';
        vector<string>ans;
        ans.push_back(rowTop);
        for(int i = 1;i<m;i++)ans.push_back(remain);
        return ans;
    }
};
