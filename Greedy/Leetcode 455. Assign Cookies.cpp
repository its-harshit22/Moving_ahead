class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int n = g.size();
        int m = s.size();
        int counter = 0;
        int l = 0;
        int r = 0;
        while(l<n && r<m){
            if(g[l]<=s[r]){
                l++;
                r++;
                counter++;
            }
            else{
                r++;
            }
        }
        return counter;
    }
};
